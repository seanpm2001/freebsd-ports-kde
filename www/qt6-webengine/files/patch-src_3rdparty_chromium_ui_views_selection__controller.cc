--- src/3rdparty/chromium/ui/views/selection_controller.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/ui/views/selection_controller.cc
@@ -26,7 +26,7 @@ SelectionController::SelectionController(SelectionCont
 // On Linux, update the selection clipboard on a text selection.
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   set_handles_selection_clipboard(true);
 #endif
 
