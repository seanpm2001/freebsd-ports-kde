--- src/3rdparty/chromium/ui/gl/gl_features.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/ui/gl/gl_features.cc
@@ -23,8 +23,8 @@ const base::Feature kGpuVsync{"GpuVsync", base::FEATUR
 // Launched on Windows, still experimental on other platforms.
 const base::Feature kDefaultPassthroughCommandDecoder{
   "DefaultPassthroughCommandDecoder",
-#if defined(OS_WIN) ||                                       \
-    ((defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
+#if defined(OS_WIN) ||                                                          \
+    ((defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)) && \
      !defined(CHROMECAST_BUILD))
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
