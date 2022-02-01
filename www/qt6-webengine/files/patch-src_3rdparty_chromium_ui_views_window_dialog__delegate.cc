--- src/3rdparty/chromium/ui/views/window/dialog_delegate.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/ui/views/window/dialog_delegate.cc
@@ -72,7 +72,7 @@ Widget* DialogDelegate::CreateDialogWidget(
 
 // static
 bool DialogDelegate::CanSupportCustomFrame(gfx::NativeView parent) {
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && \
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && \
     BUILDFLAG(ENABLE_DESKTOP_AURA)
   // The new style doesn't support unparented dialogs on Linux desktop.
   return parent != nullptr;
