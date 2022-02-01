--- src/3rdparty/chromium/third_party/perfetto/tools/busy_threads/busy_threads.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/third_party/perfetto/tools/busy_threads/busy_threads.cc
@@ -29,7 +29,8 @@
 #define PERFETTO_HAVE_PTHREADS                \
   (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-   PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE))
+   PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) ||   \
+   PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD))
 
 #if PERFETTO_HAVE_PTHREADS
 #include <pthread.h>
