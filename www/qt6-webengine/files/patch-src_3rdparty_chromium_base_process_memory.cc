--- src/3rdparty/chromium/base/process/memory.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/base/process/memory.cc
@@ -68,7 +68,7 @@ void TerminateBecauseOutOfMemory(size_t size) {
 }
 
 // Defined in memory_mac.mm for Mac.
-#if !defined(OS_APPLE)
+#if !defined(OS_APPLE) && !defined(OS_BSD)
 
 bool UncheckedCalloc(size_t num_items, size_t size, void** result) {
   const size_t alloc_size = num_items * size;
