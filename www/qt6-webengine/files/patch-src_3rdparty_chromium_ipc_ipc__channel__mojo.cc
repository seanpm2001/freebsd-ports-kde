--- src/3rdparty/chromium/ipc/ipc_channel_mojo.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/ipc/ipc_channel_mojo.cc
@@ -76,10 +76,10 @@ class MojoChannelFactory : public ChannelFactory {
 };
 
 base::ProcessId GetSelfPID() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (int global_pid = Channel::GetGlobalPid())
     return global_pid;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #if defined(OS_NACL)
   return -1;
 #else
