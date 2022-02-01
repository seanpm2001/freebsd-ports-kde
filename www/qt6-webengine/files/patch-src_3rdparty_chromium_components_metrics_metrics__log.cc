--- src/3rdparty/chromium/components/metrics/metrics_log.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/components/metrics/metrics_log.cc
@@ -241,7 +241,7 @@ void MetricsLog::RecordCoreSystemProfile(
 // OperatingSystemVersion refers to the ChromeOS release version.
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   os->set_kernel_version(base::SysInfo::KernelVersion());
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // Linux operating system version is copied over into kernel version to be
   // consistent.
   os->set_kernel_version(base::SysInfo::OperatingSystemVersion());
