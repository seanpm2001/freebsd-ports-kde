--- src/core/api/qt_cmdline.cmake.orig	2021-12-20 17:39:07 UTC
+++ src/core/api/qt_cmdline.cmake
@@ -25,7 +25,7 @@ function(qt_commandline_jumbo arg val nextok)
 endfunction()
 
 set(systemLibs alsa ffmpeg freetype harfbuzz icu lcms2 libevent libjpeg
-    libpng libvpx libxml libwebp minizip opus pulseaudio re2 snappy zlib)
+    libpng libvpx libxml libwebp minizip opus pulseaudio re2 snappy sndio zlib)
 foreach(slib ${systemLibs})
     qt_commandline_option(webengine-${slib} TYPE enum NAME webengine-system-${slib} VALUES yes no system)
 endforeach()
