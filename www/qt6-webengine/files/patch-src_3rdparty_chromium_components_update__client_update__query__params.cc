--- src/3rdparty/chromium/components/update_client/update_query_params.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/components/update_client/update_query_params.cc
@@ -40,6 +40,8 @@ const char kOs[] =
     "fuchsia";
 #elif defined(OS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
