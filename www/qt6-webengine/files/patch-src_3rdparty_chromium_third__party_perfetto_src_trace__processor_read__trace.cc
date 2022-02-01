--- src/3rdparty/chromium/third_party/perfetto/src/trace_processor/read_trace.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/third_party/perfetto/src/trace_processor/read_trace.cc
@@ -33,7 +33,8 @@
 #include "protos/perfetto/trace/trace_packet.pbzero.h"
 
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 #define PERFETTO_HAS_AIO_H() 1
 #else
 #define PERFETTO_HAS_AIO_H() 0
