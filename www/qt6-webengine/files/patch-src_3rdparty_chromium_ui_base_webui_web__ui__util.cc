--- src/3rdparty/chromium/ui/base/webui/web_ui_util.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/ui/base/webui/web_ui_util.cc
@@ -226,7 +226,7 @@ std::string GetFontFamily() {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   const base::CommandLine* cmdline = base::CommandLine::ForCurrentProcess();
   if (!cmdline->HasSwitch(switches::kSingleProcess)) {
     std::string font_name = ui::ResourceBundle::GetSharedInstance()
