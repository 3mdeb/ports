--- gusb/gusb-context.c.orig	2021-03-12 16:08:58 UTC
+++ gusb/gusb-context.c
@@ -444,6 +444,7 @@ g_usb_context_rescan (GUsbContext *context)
 	libusb_free_device_list (dev_list, 1);
 }
 
+#ifdef __linux__
 static gboolean
 g_usb_context_rescan_cb (gpointer user_data)
 {
@@ -451,6 +452,7 @@ g_usb_context_rescan_cb (gpointer user_data)
 	g_usb_context_rescan (context);
 	return TRUE;
 }
+#endif
 
 
 /**
@@ -516,12 +518,14 @@ g_usb_context_enumerate (GUsbContext *context)
 		return;
 
 	g_usb_context_rescan (context);
+#ifdef __linux__
 	if (!libusb_has_capability (LIBUSB_CAP_HAS_HOTPLUG)) {
 		g_debug ("platform does not do hotplug, using polling");
 		priv->hotplug_poll_id = g_timeout_add_seconds (1,
 							       g_usb_context_rescan_cb,
 							       context);
 	}
+#endif
 	priv->done_enumerate = TRUE;
 }
 
@@ -616,7 +620,10 @@ g_usb_context_initable_init (GInitable     *initable,
 					   context);
 
 	/* watch for add/remove */
+#ifdef __linux__
 	if (libusb_has_capability (LIBUSB_CAP_HAS_HOTPLUG)) {
+#endif
+#ifndef __OpenBSD__
 		rc = libusb_hotplug_register_callback (priv->ctx,
 						       LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED |
 						       LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT,
@@ -631,7 +638,10 @@ g_usb_context_initable_init (GInitable     *initable,
 			g_warning ("Error creating a hotplug callback: %s",
 				   g_usb_strerror (rc));
 		}
+#endif
+#ifdef __linux__
 	}
+#endif
 
 	return TRUE;
 }
