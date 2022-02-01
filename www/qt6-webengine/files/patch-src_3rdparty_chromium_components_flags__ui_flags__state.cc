--- src/3rdparty/chromium/components/flags_ui/flags_state.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/components/flags_ui/flags_state.cc
@@ -688,7 +688,7 @@ int FlagsState::GetCurrentPlatform() {
   return kOsWin;
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
   return kOsCrOS;
-#elif (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#elif (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_FREEBSD) || \
     defined(OS_OPENBSD)
   return kOsLinux;
 #elif defined(OS_ANDROID)
