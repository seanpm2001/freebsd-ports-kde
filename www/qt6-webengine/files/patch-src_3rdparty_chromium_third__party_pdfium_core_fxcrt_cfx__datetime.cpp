--- src/3rdparty/chromium/third_party/pdfium/core/fxcrt/cfx_datetime.cpp.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/third_party/pdfium/core/fxcrt/cfx_datetime.cpp
@@ -10,7 +10,7 @@
 #include "core/fxcrt/fx_system.h"
 #include "third_party/base/check.h"
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_APPLE) || defined(OS_ASMJS)
 #include <sys/time.h>
 #include <time.h>
