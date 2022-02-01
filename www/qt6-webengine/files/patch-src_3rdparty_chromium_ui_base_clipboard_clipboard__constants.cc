--- src/3rdparty/chromium/ui/base/clipboard/clipboard_constants.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/ui/base/clipboard/clipboard_constants.cc
@@ -18,11 +18,11 @@ const char kMimeTypeSvg[] = "image/svg+xml";
 const char kMimeTypeRTF[] = "text/rtf";
 const char kMimeTypePNG[] = "image/png";
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const char kMimeTypeLinuxUtf8String[] = "UTF8_STRING";
 const char kMimeTypeLinuxString[] = "STRING";
 const char kMimeTypeLinuxText[] = "TEXT";
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 
 #if !defined(OS_APPLE) || defined(TOOLKIT_QT)
 const char kMimeTypeWebCustomData[] = "chromium/x-web-custom-data";
