--- src/3rdparty/chromium/third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -158,7 +158,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     return true;
 #else
     return false;
