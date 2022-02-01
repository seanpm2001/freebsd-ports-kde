--- src/3rdparty/chromium/gpu/command_buffer/service/program_manager.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/gpu/command_buffer/service/program_manager.cc
@@ -30,7 +30,11 @@
 #include "gpu/command_buffer/service/program_cache.h"
 #include "gpu/command_buffer/service/shader_manager.h"
 #include "gpu/config/gpu_preferences.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "ui/gl/gl_version_info.h"
 #include "ui/gl/progress_reporter.h"
 
