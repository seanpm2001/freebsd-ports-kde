--- cmake/Functions.cmake.orig	2021-12-28 04:10:45 UTC
+++ cmake/Functions.cmake
@@ -388,7 +388,7 @@ function(extend_cmake_target target buildDir)
     set(objects_rsp "${buildDir}/${ninjaTarget}_objects.rsp")
     set(archives_rsp "${buildDir}/${ninjaTarget}_archives.rsp")
     set(libs_rsp "${buildDir}/${ninjaTarget}_libs.rsp")
-    if(LINUX)
+    if(LINUX OR FREEBSD)
          target_link_options(${cmakeTarget} PRIVATE
              "$<$<CONFIG:${config}>:@${objects_rsp}>"
          )
@@ -551,6 +551,8 @@ function(get_gn_os result)
         set(${result} "mac" PARENT_SCOPE)
     elseif(IOS)
         set(${result} "ios" PARENT_SCOPE)
+    elseif(FREEBSD)
+        set(${result} "freebsd" PARENT_SCOPE)
     else()
         message(DEBUG "Unrecognized OS")
     endif()
@@ -853,7 +855,7 @@ macro(append_sanitizer_setup)
 endmacro()
 
 macro(append_toolchain_setup)
-    if(LINUX)
+    if(LINUX OR FREEBSD)
         list(APPEND gnArgArg
             custom_toolchain="${buildDir}/target_toolchain:target"
             host_toolchain="${buildDir}/host_toolchain:host"
@@ -876,7 +878,7 @@ endmacro()
 
 
 macro(append_pkg_config_setup)
-    if(LINUX)
+    if(LINUX OR FREEBSD)
         list(APPEND gnArgArg
             pkg_config="${PKG_CONFIG_EXECUTABLE}"
             host_pkg_config="${PKG_CONFIG_HOST_EXECUTABLE}"
