--- src/3rdparty/chromium/base/bind.h.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/base/bind.h
@@ -313,7 +313,7 @@ inline OnceCallback<MakeUnboundRunType<Functor, Args..
                      !std::is_const<std::remove_reference_t<Functor>>()),
                 "BindOnce requires non-const rvalue for OnceCallback binding."
                 " I.e.: base::BindOnce(std::move(callback)).");
-#if defined(OS_LINUX) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(NCTEST_BIND_ONCE_WITH_PASSED)
   // TODO(https://crbug.com/1180750): Enable this everywhere.
   static_assert(
