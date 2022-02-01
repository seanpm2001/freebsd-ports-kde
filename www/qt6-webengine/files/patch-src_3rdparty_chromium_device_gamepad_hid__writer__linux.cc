--- src/3rdparty/chromium/device/gamepad/hid_writer_linux.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/device/gamepad/hid_writer_linux.cc
@@ -4,6 +4,8 @@
 
 #include "device/gamepad/hid_writer_linux.h"
 
+#include <unistd.h>
+
 #include "base/posix/eintr_wrapper.h"
 
 namespace device {
