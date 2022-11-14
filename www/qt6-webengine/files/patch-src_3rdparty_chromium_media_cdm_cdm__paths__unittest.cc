--- src/3rdparty/chromium/media/cdm/cdm_paths_unittest.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/media/cdm/cdm_paths_unittest.cc
@@ -27,7 +27,7 @@ const char kComponentPlatform[] =
     "win";
 #elif BUILDFLAG(IS_CHROMEOS)
     "cros";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     "linux";
 #else
     "unsupported_platform";
