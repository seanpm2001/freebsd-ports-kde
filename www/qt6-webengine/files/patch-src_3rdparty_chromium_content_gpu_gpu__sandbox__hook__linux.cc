--- src/3rdparty/chromium/content/gpu/gpu_sandbox_hook_linux.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/content/gpu/gpu_sandbox_hook_linux.cc
@@ -99,7 +99,7 @@ static const char kLibV4lEncPluginPath[] =
     "/usr/lib/libv4l/plugins/libv4l-encplugin.so";
 #endif
 
-constexpr int dlopen_flag = RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE;
+constexpr int dlopen_flag = RTLD_NOW | RTLD_GLOBAL;
 
 void AddV4L2GpuPermissions(
     std::vector<BrokerFilePermission>* permissions,
@@ -378,6 +378,7 @@ std::vector<BrokerFilePermission> FilePermissionsForGp
 }
 
 void LoadArmGpuLibraries() {
+#if !defined(OS_BSD)
   // Preload the Mali library.
   if (UseChromecastSandboxAllowlist()) {
     for (const char* path : kAllowedChromecastPaths) {
@@ -410,6 +411,7 @@ void LoadArmGpuLibraries() {
         dlopen(driver_paths[i], dlopen_flag);
     }
   }
+#endif
 }
 
 bool LoadAmdGpuLibraries() {
@@ -488,6 +490,7 @@ bool LoadLibrariesForGpu(
   return true;
 }
 
+#if !defined(OS_BSD)
 sandbox::syscall_broker::BrokerCommandSet CommandSetForGPU(
     const sandbox::policy::SandboxLinux::Options& options) {
   sandbox::syscall_broker::BrokerCommandSet command_set;
@@ -510,13 +513,17 @@ bool BrokerProcessPreSandboxHook(
   SetProcessTitleFromCommandLine(nullptr);
   return true;
 }
+#endif
 
 }  // namespace
 
 bool GpuProcessPreSandboxHook(sandbox::policy::SandboxLinux::Options options) {
+  NOTIMPLEMENTED();
+#if !defined(OS_BSD)
   sandbox::policy::SandboxLinux::GetInstance()->StartBrokerProcess(
       CommandSetForGPU(options), FilePermissionsForGpu(options),
       base::BindOnce(BrokerProcessPreSandboxHook), options);
+#endif
 
   if (!LoadLibrariesForGpu(options))
     return false;
