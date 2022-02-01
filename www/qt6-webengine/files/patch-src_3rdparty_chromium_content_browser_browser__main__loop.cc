--- src/3rdparty/chromium/content/browser/browser_main_loop.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/content/browser/browser_main_loop.cc
@@ -373,7 +373,7 @@ std::unique_ptr<base::MemoryPressureMonitor> CreateMem
   if (chromeos::switches::MemoryPressureHandlingEnabled())
     monitor = std::make_unique<util::MultiSourceMemoryPressureMonitor>();
 #elif defined(OS_MAC) || defined(OS_WIN) || defined(OS_FUCHSIA) || \
-    ((defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) &&       \
+    defined(OS_BSD) || ((defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
      !BUILDFLAG(IS_CHROMECAST))
   monitor = std::make_unique<util::MultiSourceMemoryPressureMonitor>();
 #endif
@@ -567,7 +567,7 @@ int BrowserMainLoop::EarlyInitialization() {
 
   // Up the priority of the UI thread unless it was already high (since Mac
   // and recent versions of Android (O+) do this automatically).
-#if !defined(OS_MAC)
+#if !defined(OS_MAC) && !defined(OS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kBrowserUseDisplayThreadPriority) &&
       base::PlatformThread::GetCurrentThreadPriority() <
@@ -577,7 +577,7 @@ int BrowserMainLoop::EarlyInitialization() {
   }
 #endif  // !defined(OS_MAC)
 
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_ANDROID)
   // We use quite a few file descriptors for our IPC as well as disk the disk
   // cache,and the default limit on the Mac is low (256), so bump it up.
@@ -587,7 +587,7 @@ int BrowserMainLoop::EarlyInitialization() {
   // users can easily hit this limit with many open tabs. Bump up the limit to
   // an arbitrarily high number. See https://crbug.com/539567
   base::IncreaseFdLimitTo(8192);
-#endif  // defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) ||
+#endif  // defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) ||
         // defined(OS_ANDROID)
 
 #if defined(OS_WIN)
