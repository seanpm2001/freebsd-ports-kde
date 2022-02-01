--- src/3rdparty/chromium/chrome/common/chrome_switches.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/chrome/common/chrome_switches.cc
@@ -804,7 +804,7 @@ const char kAllowNaClFileHandleAPI[]        = "allow-n
 const char kAllowNaClSocketAPI[]            = "allow-nacl-socket-api";
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
 const char kEnableNewAppMenuIcon[] = "enable-new-app-menu-icon";
 
