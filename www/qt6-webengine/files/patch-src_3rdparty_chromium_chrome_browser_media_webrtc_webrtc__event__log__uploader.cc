--- src/3rdparty/chromium/chrome/browser/media/webrtc/webrtc_event_log_uploader.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/chrome/browser/media/webrtc/webrtc_event_log_uploader.cc
@@ -43,6 +43,8 @@ const char kProduct[] = "Chrome_Mac";
 const char kProduct[] = "Chrome_ChromeOS";
 #elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
 const char kProduct[] = "Chrome_Linux";
+#elif defined(OS_FREEBSD)
+const char kProduct[] = "Chrome_FreeBSD";
 #elif defined(OS_ANDROID)
 const char kProduct[] = "Chrome_Android";
 #else
