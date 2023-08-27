--- configure.cmake.orig	2023-08-16 19:50:41 UTC
+++ configure.cmake
@@ -67,7 +67,7 @@ endif()
 endif()
 
 #### Tests
-if(LINUX)
+if(LINUX OR FREEBSD)
    check_for_ulimit()
 endif()
 
@@ -438,7 +438,7 @@ qt_feature("webengine-ozone-x11" PRIVATE
 
 qt_feature("webengine-ozone-x11" PRIVATE
     LABEL "Support GLX on qpa-xcb"
-    CONDITION LINUX
+    CONDITION LINUX OR FREEBSD
         AND TARGET Qt::Gui
         AND QT_FEATURE_xcb
         AND X11_FOUND
@@ -475,12 +475,12 @@ add_check_for_support(
 )
 add_check_for_support(
    MODULES QtWebEngine
-   CONDITION LINUX OR (WIN32 AND NOT WIN_ARM_64) OR MACOS
+   CONDITION LINUX OR (WIN32 AND NOT WIN_ARM_64) OR MACOS OR FREEBSD
    MESSAGE "Build can be done only on Linux, Windows or macOS."
 )
 add_check_for_support(
    MODULES QtPdf
-   CONDITION LINUX OR (WIN32 AND NOT WIN_ARM_64) OR MACOS OR IOS OR (ANDROID AND NOT CMAKE_HOST_WIN32)
+   CONDITION LINUX OR (WIN32 AND NOT WIN_ARM_64) OR MACOS OR IOS OR (ANDROID AND NOT CMAKE_HOST_WIN32) OR FREEBSD
    MESSAGE "Build can be done only on Linux, Windows, macO, iOS and Android(on non-Windows hosts only)."
 )
 if(LINUX AND CMAKE_CROSSCOMPILING)
@@ -586,8 +586,8 @@ add_check_for_support(
 add_check_for_support(
    MODULES QtWebEngine
    CONDITION MSVC OR
-       (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL GNU) OR
-       (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL Clang) OR
+       (FREEBSD AND CMAKE_CXX_COMPILER_ID STREQUAL GNU) OR
+       (FREEBSD AND CMAKE_CXX_COMPILER_ID STREQUAL Clang) OR
        (MACOS AND CMAKE_CXX_COMPILER_ID STREQUAL AppleClang)
    MESSAGE
        "${CMAKE_CXX_COMPILER_ID} compiler is not supported."
@@ -596,8 +596,8 @@ add_check_for_support(
 add_check_for_support(
    MODULES QtPdf
    CONDITION MSVC OR
-       (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL GNU) OR
-       (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL Clang) OR
+       (FREEBSD AND CMAKE_CXX_COMPILER_ID STREQUAL GNU) OR
+       (FREEBSD AND CMAKE_CXX_COMPILER_ID STREQUAL Clang) OR
        (APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL AppleClang) OR
        (ANDROID AND CMAKE_CXX_COMPILER_ID STREQUAL Clang) OR
        (MINGW AND CMAKE_CXX_COMPILER_ID STREQUAL GNU) OR
