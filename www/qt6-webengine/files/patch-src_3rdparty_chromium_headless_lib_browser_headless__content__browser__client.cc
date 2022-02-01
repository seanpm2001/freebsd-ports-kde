--- src/3rdparty/chromium/headless/lib/browser/headless_content_browser_client.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/headless/lib/browser/headless_content_browser_client.cc
@@ -279,7 +279,7 @@ void HeadlessContentBrowserClient::AppendExtraCommandL
                                             process_type, child_process_id);
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Processes may only query perf_event_open with the BPF sandbox disabled.
   if (old_command_line.HasSwitch(::switches::kEnableThreadInstructionCount) &&
       old_command_line.HasSwitch(sandbox::policy::switches::kNoSandbox)) {
