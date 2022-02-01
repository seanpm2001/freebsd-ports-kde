--- src/3rdparty/chromium/net/http/http_auth_gssapi_posix.h.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/net/http/http_auth_gssapi_posix.h
@@ -21,6 +21,9 @@
 #include <GSS/gssapi.h>
 #elif defined(OS_FREEBSD)
 #include <gssapi/gssapi.h>
+#ifndef GSS_C_DELEG_POLICY_FLAG
+#define GSS_C_DELEG_POLICY_FLAG 32768
+#endif
 #else
 #include <gssapi.h>
 #endif
