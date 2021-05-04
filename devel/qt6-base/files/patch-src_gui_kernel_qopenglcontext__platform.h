--- src/gui/kernel/qopenglcontext_platform.h.orig	2020-12-23 10:30:22 UTC
+++ src/gui/kernel/qopenglcontext_platform.h
@@ -50,7 +50,7 @@
 Q_FORWARD_DECLARE_OBJC_CLASS(NSOpenGLContext);
 #endif
 
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 struct __GLXcontextRec; typedef struct __GLXcontextRec *GLXContext;
 #endif
 #if QT_CONFIG(egl)
@@ -85,7 +85,7 @@ struct Q_GUI_EXPORT QWGLContext
 };
 #endif
 
-#if defined(Q_OS_LINUX) || defined(Q_CLANG_QDOC)
+#if defined(Q_OS_LINUX) || defined(Q_CLANG_QDOC) || defined(Q_OS_FREEBSD)
 struct Q_GUI_EXPORT QGLXContext
 {
     QT_DECLARE_NATIVE_INTERFACE(QGLXContext)
