--- src/3rdparty/chromium/net/dns/dns_util.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/net/dns/dns_util.cc
@@ -28,6 +28,8 @@
 #include "net/third_party/uri_template/uri_template.h"
 #include "url/url_canon.h"
 
+#include <sys/socket.h>
+
 #if defined(OS_POSIX)
 #include <netinet/in.h>
 #if !defined(OS_NACL)
