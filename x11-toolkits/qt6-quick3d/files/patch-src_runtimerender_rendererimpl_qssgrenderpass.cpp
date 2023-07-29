Fix bulk builds in poudriere. Regressed by [1]. Quick3DRuntimeRender needs to
build before QtQuick3D, so I'm not sure why this include was added.

/wrkdirs/usr/ports/x11-toolkits/qt6-quick3d/work/qtquick3d-everywhere-src-6.6.0-beta2/src/runtimerender/rendererimpl/qssgrenderpass.cpp:16:10:
fatal error: 'QtQuick3D/QQuick3DObject' file not found
#include <QtQuick3D/QQuick3DObject>

[1] https://code.qt.io/cgit/qt/qtquick3d.git/commit/src?h=6.6&id=1bca206a3516875896b92508b0de9dcdaae7dfba

--- src/runtimerender/rendererimpl/qssgrenderpass.cpp.orig	2023-07-29 15:40:05 UTC
+++ src/runtimerender/rendererimpl/qssgrenderpass.cpp
@@ -13,8 +13,6 @@
 #include <QtQuick/private/qsgrenderer_p.h>
 #include <qtquick3d_tracepoints_p.h>
 
-#include <QtQuick3D/QQuick3DObject>
-
 QT_BEGIN_NAMESPACE
 
 static inline QMatrix4x4 correctMVPForScissor(QRectF viewportRect, QRect scissorRect, bool isYUp) {
