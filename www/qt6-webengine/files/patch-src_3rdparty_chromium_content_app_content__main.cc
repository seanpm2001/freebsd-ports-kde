--- src/3rdparty/chromium/content/app/content_main.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/content/app/content_main.cc
@@ -231,7 +231,7 @@ int RunContentProcess(const ContentMainParams& params,
     base::EnableTerminationOnOutOfMemory();
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     // The various desktop environments set this environment variable that
     // allows the dbus client library to connect directly to the bus. When this
     // variable is not set (test environments like xvfb-run), the dbus client
