--- src/3rdparty/chromium/base/check.h.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/base/check.h
@@ -85,7 +85,7 @@ class BASE_EXPORT CheckError {
   // Stream for adding optional details to the error message.
   std::ostream& stream();
 
-  NOMERGE ~CheckError();
+  ~CheckError();
 
   CheckError(const CheckError& other) = delete;
   CheckError& operator=(const CheckError& other) = delete;
