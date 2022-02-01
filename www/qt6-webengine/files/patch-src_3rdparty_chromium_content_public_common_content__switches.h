--- src/3rdparty/chromium/content/public/common/content_switches.h.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/content/public/common/content_switches.h
@@ -252,7 +252,7 @@ CONTENT_EXPORT extern const char kWebXrRuntimeOrientat
 CONTENT_EXPORT extern const char kWebXrRuntimeOpenXr[];
 CONTENT_EXPORT extern const char kWebXrRuntimeWMR[];
 
-#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && !defined(OS_ANDROID)
+#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)) && !defined(OS_ANDROID)
 CONTENT_EXPORT extern const char kEnableAcceleratedVideoDecode[];
 #endif
 CONTENT_EXPORT extern const char kDisableAcceleratedVideoDecode[];
@@ -274,7 +274,7 @@ CONTENT_EXPORT extern const char kRendererWaitForJavaD
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 #endif
 
