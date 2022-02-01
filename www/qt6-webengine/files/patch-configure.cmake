--- configure.cmake.orig	2021-11-25 09:20:12 UTC
+++ configure.cmake
@@ -301,6 +302,7 @@ qt_feature("webengine-system-minizip" PRIVATE
 )
 qt_feature("webengine-system-libevent" PRIVATE
     LABEL "libevent"
+    # XXX Hm...
     AUTODETECT FALSE # coin bug 711
     CONDITION UNIX AND LIBEVENT_FOUND
 )
@@ -335,7 +337,7 @@ qt_feature("webengine-system-libpci" PRIVATE
 
 qt_feature("webengine-ozone-x11" PRIVATE
     LABEL "Support GLX on qpa-xcb"
-    CONDITION LINUX
+    CONDITION LINUX OR FREEBSD
         AND TARGET Qt::Gui
         AND QT_FEATURE_xcb
         AND X11_FOUND
@@ -362,7 +364,7 @@ assertTargets(
 )
 add_check_for_support(
    MODULES QtWebEngine QtPdf
-   CONDITION LINUX OR (WIN32 AND NOT WIN_ARM_64) OR (MACOS AND NOT CMAKE_CROSSCOMPILING)
+   CONDITION LINUX OR (WIN32 AND NOT WIN_ARM_64) OR (MACOS AND NOT CMAKE_CROSSCOMPILING) OR FREEBSD
    MESSAGE "Build can be done only on Linux, Windows or macOS."
 )
 if(LINUX AND CMAKE_CROSSCOMPILING)
@@ -458,6 +460,8 @@ add_check_for_support(
    CONDITION
        (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL GNU) OR
        (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL Clang) OR
+       (FREEBSD AND CMAKE_CXX_COMPILER_ID STREQUAL GNU) OR
+       (FREEBSD AND CMAKE_CXX_COMPILER_ID STREQUAL Clang) OR
        (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL MSVC) OR
        (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL Clang AND
           CMAKE_CXX_SIMULATE_ID STREQUAL MSVC) OR
