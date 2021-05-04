--- src/gui/kernel/qplatformopenglcontext.h.orig	2020-12-23 10:41:32 UTC
+++ src/gui/kernel/qplatformopenglcontext.h
@@ -127,7 +127,7 @@ struct Q_GUI_EXPORT QWindowsGLIntegration
 };
 #endif
 
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 struct Q_GUI_EXPORT QGLXIntegration
 {
     QT_DECLARE_NATIVE_INTERFACE(QGLXIntegration)
