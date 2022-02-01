--- src/3rdparty/chromium/headless/lib/headless_macros.h.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/headless/lib/headless_macros.h
@@ -7,8 +7,8 @@
 
 #include "build/build_config.h"
 
-#if defined(OS_POSIX) && !defined(OS_MAC)
+#if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_BSD)
 #define HEADLESS_USE_BREAKPAD
-#endif  // defined(OS_POSIX) && !defined(OS_MAC)
+#endif  // defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_BSD)
 
 #endif  // HEADLESS_LIB_HEADLESS_MACROS_H_
