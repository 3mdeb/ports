--- gusb/gusb-device.c.orig	2021-03-12 16:08:58 UTC
+++ gusb/gusb-device.c
@@ -38,6 +38,7 @@ struct _GUsbDevicePrivate
 	GUsbContext		*context;
 	libusb_device		*device;
 	libusb_device_handle	*handle;
+	GArray                  *port_numbers;
 	struct libusb_device_descriptor desc;
 };
 
@@ -84,6 +85,7 @@ g_usb_device_dispose (GObject *object)
 	GUsbDevice *device = G_USB_DEVICE (object);
 	GUsbDevicePrivate *priv = device->priv;
 
+	g_clear_pointer (&priv->port_numbers, g_array_unref);
 	g_clear_pointer (&priv->device, libusb_unref_device);
 	g_clear_object (&priv->context);
 
@@ -212,25 +214,20 @@ g_usb_device_init (GUsbDevice *device)
 	device->priv = g_usb_device_get_instance_private (device);
 }
 
-static void
-g_usb_device_build_parent_port_number (GString *str, libusb_device *dev)
-{
-	libusb_device *parent = libusb_get_parent (dev);
-	if (parent != NULL)
-		g_usb_device_build_parent_port_number (str, parent);
-	g_string_append_printf (str, "%02x:", libusb_get_port_number (dev));
-}
-
 static gchar *
-g_usb_device_build_platform_id (struct libusb_device *dev)
+g_usb_device_build_platform_id (GUsbDevice *device)
 {
+	GUsbDevicePrivate *priv = device->priv;
 	GString *platform_id;
+	guint i;
 
 	/* build a topology of the device */
-	platform_id = g_string_new ("usb:");
-	g_string_append_printf (platform_id, "%02x:", libusb_get_bus_number (dev));
-	g_usb_device_build_parent_port_number (platform_id, dev);
-	g_string_truncate (platform_id, platform_id->len - 1);
+	platform_id = g_string_new ("usb");
+	g_string_append_printf (platform_id, ":%02x",
+				libusb_get_bus_number (priv->device));
+	for (i = 0; i < priv->port_numbers->len; i++)
+		g_string_append_printf (platform_id, ":%02x",
+					g_array_index (priv->port_numbers, guint8, i));
 	return g_string_free (platform_id, FALSE);
 }
 
@@ -259,8 +256,32 @@ g_usb_device_initable_init (GInitable     *initable,
 		return FALSE;
 	}
 
+	/* Store port number values to ease parent device finding on FreeBSD.
+	 * FreeBSD's libusb requires a device to be opened before calling
+	 * libusb_get_port_numbers because it needs the fd to call ioctl. */
+#define PORT_NUMBER_MAX 64
+	priv->port_numbers = g_array_new (FALSE, FALSE, sizeof (guint8));
+#ifndef __linux__
+	g_return_val_if_fail (priv->handle == NULL, FALSE);
+	if (libusb_open (priv->device, &priv->handle) == LIBUSB_SUCCESS) {
+#endif
+		guint8 ports[PORT_NUMBER_MAX];
+		gint port_count;
+		port_count = libusb_get_port_numbers (priv->device, ports,
+						      PORT_NUMBER_MAX);
+		if (port_count > 0) {
+			g_array_set_size (priv->port_numbers, port_count);
+			memcpy (priv->port_numbers->data, ports, port_count);
+		}
+#ifndef __linux__
+		libusb_close (priv->handle);
+		priv->handle = NULL;
+	}
+#endif
+#undef PORT_NUMBER_MAX
+
 	/* this does not change on plug->unplug->plug */
-	priv->platform_id = g_usb_device_build_platform_id (priv->device);
+	priv->platform_id = g_usb_device_build_platform_id (device);
 
 	return TRUE;
 }
@@ -1616,6 +1637,41 @@ g_usb_device_get_platform_id (GUsbDevice *device)
 	return device->priv->platform_id;
 }
 
+static libusb_device *
+g_usb_device_get_parent_libusb_device (GUsbDevice *device)
+{
+#ifndef __linux__
+	GPtrArray *devices = NULL;
+	GUsbDevice *device_tmp;
+	gboolean found = FALSE;
+	guint i;
+
+	if (device->priv->port_numbers->len == 0)
+		return NULL;
+
+	devices = g_usb_context_get_devices (device->priv->context);
+	for (i = 0; devices->len; i++) {
+		device_tmp = g_ptr_array_index (devices, i);
+		if (g_usb_device_get_bus (device) ==
+		    g_usb_device_get_bus (device_tmp) &&
+		    device->priv->port_numbers->len - 1 ==
+		    device_tmp->priv->port_numbers->len &&
+		    memcmp (device->priv->port_numbers->data,
+			    device_tmp->priv->port_numbers->data,
+			    device_tmp->priv->port_numbers->len) == 0) {
+			found = TRUE;
+			break;
+		}
+	}
+
+	g_ptr_array_unref (devices);
+
+	return found ? device_tmp->priv->device : NULL;
+#else
+	return libusb_get_parent (device->priv->device);
+#endif
+}
+
 /**
  * g_usb_device_get_parent:
  * @device: a #GUsbDevice instance
@@ -1632,7 +1688,7 @@ g_usb_device_get_parent (GUsbDevice *device)
 	GUsbDevicePrivate *priv = device->priv;
 	libusb_device *parent;
 
-	parent = libusb_get_parent (priv->device);
+	parent = g_usb_device_get_parent_libusb_device (device);
 	if (parent == NULL)
 		return NULL;
 
@@ -1666,7 +1722,7 @@ g_usb_device_get_children (GUsbDevice *device)
 	devices = g_usb_context_get_devices (priv->context);
 	for (i = 0; i < devices->len; i++) {
 		device_tmp = g_ptr_array_index (devices, i);
-		if (priv->device == libusb_get_parent (device_tmp->priv->device))
+		if (priv->device == g_usb_device_get_parent_libusb_device (device_tmp))
 			g_ptr_array_add (children, g_object_ref (device_tmp));
 	}
 
@@ -1711,6 +1767,7 @@ g_usb_device_get_address (GUsbDevice *device)
 	return libusb_get_device_address (device->priv->device);
 }
 
+#ifndef __DragonFly__
 /**
  * g_usb_device_get_port_number:
  * @device: a #GUsbDevice
@@ -1727,6 +1784,7 @@ g_usb_device_get_port_number (GUsbDevice *device)
 	g_return_val_if_fail (G_USB_IS_DEVICE (device), 0);
 	return libusb_get_port_number (device->priv->device);
 }
+#endif
 
 /**
  * g_usb_device_get_vid:
