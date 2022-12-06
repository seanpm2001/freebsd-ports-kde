--- dooble.pro.orig	2022-12-03 17:35:47 UTC
+++ dooble.pro
@@ -9,7 +9,7 @@ qtPrepareTool(CONVERT_TOOL, qwebengine_convert_dict)
 win32 {
 qtPrepareTool(CONVERT_TOOL, qwebengine_convert_dict)
 } else {
-qtPrepareTool(CONVERT_TOOL, ../libexec/qwebengine_convert_dict)
+qtPrepareTool(CONVERT_TOOL, ../../../libexec/qt6/qwebengine_convert_dict)
 }
 } else {
 qtPrepareTool(CONVERT_TOOL, qwebengine_convert_dict)
@@ -255,7 +255,6 @@ QMAKE_CXXFLAGS_RELEASE += -O3 \
                           -Wcast-align \
                           -Wcast-qual \
                           -Wdouble-promotion \
-                          -Werror \
                           -Wextra \
                           -Wformat=2 \
                           -Woverloaded-virtual \
