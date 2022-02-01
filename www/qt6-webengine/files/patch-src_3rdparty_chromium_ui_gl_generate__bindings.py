--- src/3rdparty/chromium/ui/gl/generate_bindings.py.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/ui/gl/generate_bindings.py
@@ -2906,6 +2906,9 @@ GLX_FUNCTIONS = [
   'arguments':
       'Display* dpy, GLXDrawable drawable, int32_t* numerator, '
       'int32_t* denominator' },
+{ 'return_type': '__GLXextFuncPtr',
+  'names': ['glXGetProcAddressARB'],
+  'arguments': 'const GLubyte* procName', },
 { 'return_type': 'void',
   'names': ['glXGetSelectedEvent'],
   'arguments': 'Display* dpy, GLXDrawable drawable, unsigned long* mask', },
