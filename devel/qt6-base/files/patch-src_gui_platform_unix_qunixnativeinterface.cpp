--- src/gui/platform/unix/qunixnativeinterface.cpp.orig	2021-03-31 06:51:56 UTC
+++ src/gui/platform/unix/qunixnativeinterface.cpp
@@ -55,7 +55,7 @@ using namespace QNativeInterface::Private;
 
 #ifndef QT_NO_OPENGL
 
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 
 /*!
     \class QNativeInterface::QGLXContext
