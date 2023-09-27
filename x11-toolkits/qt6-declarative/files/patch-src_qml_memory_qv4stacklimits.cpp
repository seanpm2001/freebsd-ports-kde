FreeBSD's pthread_attr_get_np(3) doesn't automatically initialize attr.

Regressed by: https://code.qt.io/cgit/qt/qtdeclarative.git/commit/?h=6.6.0&id=a8152e5933a9dd53eb60b422e711212e7d91c29a
QTBUG-117513: https://bugreports.qt.io/browse/QTBUG-117513

--- src/qml/memory/qv4stacklimits.cpp.orig	2023-09-21 06:51:29 UTC
+++ src/qml/memory/qv4stacklimits.cpp
@@ -235,6 +235,7 @@ StackProperties stackPropertiesGeneric(qsizetype stack
     pthread_t thread = pthread_self();
     pthread_attr_t sattr;
 #  if defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(Q_OS_NETBSD)
+    pthread_attr_init(&sattr);
     pthread_attr_get_np(thread, &sattr);
 #  else
     pthread_getattr_np(thread, &sattr);
