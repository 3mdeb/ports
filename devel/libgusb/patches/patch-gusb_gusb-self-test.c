--- gusb/gusb-self-test.c.orig	2021-03-12 16:08:58 UTC
+++ gusb/gusb-self-test.c
@@ -32,8 +32,15 @@ gusb_device_func (void)
 	g_assert_cmpint (array->len, >, 0);
 	device = G_USB_DEVICE (g_ptr_array_index (array, 0));
 
-	g_assert_cmpint (g_usb_device_get_vid (device), >, 0x0000);
-	g_assert_cmpint (g_usb_device_get_pid (device), >, 0x0000);
+	/* Root hubs on FreeBSD have vid and pid set to zero */
+#ifndef __linux__
+	if (g_usb_device_get_parent (device) != NULL) {
+#endif
+		g_assert_cmpint (g_usb_device_get_vid (device), >, 0x0000);
+		g_assert_cmpint (g_usb_device_get_pid (device), >, 0x0000);
+#ifndef __linux__
+	}
+#endif
 
 	g_ptr_array_unref (array);
 }
@@ -88,8 +95,14 @@ gusb_context_func (void)
 	for (i = 0; i < array->len; i++) {
 		device = G_USB_DEVICE (g_ptr_array_index (array, i));
 
-		g_assert_cmpint (g_usb_device_get_vid (device), >, 0x0000);
-		g_assert_cmpint (g_usb_device_get_pid (device), >, 0x0000);
+#ifndef __linux__
+		if (g_usb_device_get_parent (device) != NULL) {
+#endif
+			g_assert_cmpint (g_usb_device_get_vid (device), >, 0x0000);
+			g_assert_cmpint (g_usb_device_get_pid (device), >, 0x0000);
+#ifndef __linux__
+		}
+#endif
 
 		/* Needed for g_usb_device_get_string_descriptor below,
 		   not error checked to allow running basic tests without
