--- src/3rdparty/chromium/media/base/user_input_monitor_unittest.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/media/base/user_input_monitor_unittest.cc
@@ -13,7 +13,7 @@
 #include "build/build_config.h"
 #include "testing/gtest/include/gtest/gtest.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/file_descriptor_watcher_posix.h"
 #endif
 
@@ -49,7 +49,7 @@ TEST_F(UserInputMonitorTest, CreatePlatformSpecific) {
 }  // namespace
 
 TEST_F(UserInputMonitorTest, CreatePlatformSpecific) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::test::TaskEnvironment task_environment(
       base::test::TaskEnvironment::MainThreadType::IO);
 #else
@@ -71,7 +71,7 @@ TEST_F(UserInputMonitorTest, CreatePlatformSpecificWit
 }
 
 TEST_F(UserInputMonitorTest, CreatePlatformSpecificWithMapping) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::test::TaskEnvironment task_environment(
       base::test::TaskEnvironment::MainThreadType::IO);
 #else
