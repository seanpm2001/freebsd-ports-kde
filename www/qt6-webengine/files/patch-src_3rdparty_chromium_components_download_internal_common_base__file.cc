--- src/3rdparty/chromium/components/download/internal/common/base_file.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/components/download/internal/common/base_file.cc
@@ -607,7 +607,7 @@ GURL GetEffectiveAuthorityURL(const GURL& source_url,
 
 }  // namespace
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformationSync(
@@ -626,7 +626,7 @@ DownloadInterruptReason BaseFile::AnnotateWithSourceIn
 
   return QuarantineFileResultToReason(result);
 }
-#else  // !OS_WIN && !OS_APPLE && !OS_LINUX && !OS_CHROMEOS
+#else  // !OS_WIN && !OS_APPLE && !OS_LINUX && !OS_CHROMEOS && !OS_BSD
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformationSync(
     const std::string& client_guid,
     const GURL& source_url,
