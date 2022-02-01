--- src/core/api/configure.cmake.orig	2021-11-25 09:20:12 UTC
+++ src/core/api/configure.cmake
@@ -5,6 +5,7 @@ if(NOT QT_CONFIGURE_RUNNING)
     if(PkgConfig_FOUND)
         pkg_check_modules(ALSA alsa IMPORTED_TARGET)
         pkg_check_modules(PULSEAUDIO libpulse>=0.9.10 libpulse-mainloop-glib)
+	pkg_check_modules(SNDIO libsndio)
         pkg_check_modules(GIO gio-2.0)
         pkg_check_modules(XDAMAGE xdamage)
     endif()
@@ -53,6 +54,11 @@ qt_feature("webengine-system-pulseaudio" PRIVATE
     AUTODETECT UNIX
     CONDITION PULSEAUDIO_FOUND
 )
+qt_feature("webengine-system-sndio" PRIVATE
+    LABEL "Use sndio"
+    AUTODETECT UNIX
+    CONDITION SNDIO_FOUND
+)
 qt_feature("webengine-pepper-plugins" PRIVATE
     LABEL "Pepper Plugins"
     PURPOSE "Enables use of Pepper Flash plugins."
@@ -155,6 +161,10 @@ qt_configure_add_summary_entry(
 )
 qt_configure_add_summary_entry(
     ARGS "webengine-system-pulseaudio"
+    CONDITION UNIX
+)
+qt_configure_add_summary_entry(
+    ARGS "webengine-system-sndio"
     CONDITION UNIX
 )
 qt_configure_end_summary_section() # end of "Qt WebEngineCore" section
