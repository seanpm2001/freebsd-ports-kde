--- src/3rdparty/chromium/v8/src/base/cpu.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/v8/src/base/cpu.cc
@@ -545,6 +545,7 @@ CPU::CPU()
 
 #if V8_OS_LINUX
 
+#if V8_OS_LINUX
   CPUInfo cpu_info;
 
   // Extract implementor from the "CPU implementer" field.
@@ -578,6 +579,7 @@ CPU::CPU()
     }
     delete[] part;
   }
+#endif
 
   // Extract architecture from the "CPU Architecture" field.
   // The list is well-known, unlike the the output of
