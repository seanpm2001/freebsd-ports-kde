--- src/3rdparty/chromium/ui/views/views_delegate.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/ui/views/views_delegate.cc
@@ -90,7 +90,7 @@ bool ViewsDelegate::IsWindowInMetro(gfx::NativeWindow 
   return false;
 }
 #elif BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return nullptr;
 }
