--- src/3rdparty/chromium/ui/base/cursor/cursor_factory.h.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/ui/base/cursor/cursor_factory.h
@@ -67,7 +67,7 @@ class COMPONENT_EXPORT(UI_BASE_CURSOR_BASE) CursorFact
   virtual void ObserveThemeChanges();
 };
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 COMPONENT_EXPORT(UI_BASE_CURSOR_BASE)
 std::vector<std::string> CursorNamesFromType(mojom::CursorType type);
 #endif
