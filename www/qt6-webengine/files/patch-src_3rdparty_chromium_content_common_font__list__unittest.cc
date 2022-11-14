--- src/3rdparty/chromium/content/common/font_list_unittest.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/content/common/font_list_unittest.cc
@@ -50,7 +50,7 @@ TEST(FontList, GetFontList) {
         EXPECT_TRUE(HasFontWithName(*fonts, "MS Gothic", "MS Gothic"));
         EXPECT_TRUE(HasFontWithName(*fonts, "Segoe UI", "Segoe UI"));
         EXPECT_TRUE(HasFontWithName(*fonts, "Verdana", "Verdana"));
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
         EXPECT_TRUE(HasFontWithName(*fonts, "Arimo", "Arimo"));
 #else
         EXPECT_TRUE(HasFontWithName(*fonts, "Arial", "Arial"));
