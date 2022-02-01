--- src/3rdparty/chromium/services/device/geolocation/location_arbitrator.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/services/device/geolocation/location_arbitrator.cc
@@ -165,7 +165,7 @@ LocationArbitrator::NewNetworkLocationProvider(
 
 std::unique_ptr<LocationProvider>
 LocationArbitrator::NewSystemLocationProvider() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider();
