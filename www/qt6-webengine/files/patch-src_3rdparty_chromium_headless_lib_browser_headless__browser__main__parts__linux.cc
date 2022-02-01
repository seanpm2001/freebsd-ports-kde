--- src/3rdparty/chromium/headless/lib/browser/headless_browser_main_parts_linux.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/headless/lib/browser/headless_browser_main_parts_linux.cc
@@ -11,7 +11,7 @@
 namespace headless {
 
 void HeadlessBrowserMainParts::PostMainMessageLoopStart() {
-#if defined(USE_DBUS) && !BUILDFLAG(IS_CHROMEOS_ASH)
+#if defined(USE_DBUS) && !BUILDFLAG(IS_CHROMEOS_ASH) && !defined(OS_BSD)
   bluez::BluezDBusManager::Initialize(/*system_bus=*/nullptr);
 #endif
 }
