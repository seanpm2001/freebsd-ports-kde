--- cmake/Functions.cmake.orig	2022-11-08 21:18:48 UTC
+++ cmake/Functions.cmake
@@ -429,7 +429,7 @@ function(add_linker_options target buildDir completeSt
     set(archives_rsp "${buildDir}/${ninjaTarget}_archives.rsp")
     set(libs_rsp "${buildDir}/${ninjaTarget}_libs.rsp")
     set_target_properties(${cmakeTarget} PROPERTIES STATIC_LIBRARY_OPTIONS "@${objects_rsp}")
-    if(LINUX)
+    if(LINUX OR FREEBSD)
          get_gn_arch(cpu ${TEST_architecture_arch})
          if(CMAKE_CROSSCOMPILING AND cpu STREQUAL "arm" AND ${config} STREQUAL "Debug")
              target_link_options(${cmakeTarget} PRIVATE "LINKER:--long-plt")
@@ -667,6 +667,8 @@ function(get_gn_os result)
         set(${result} "mac" PARENT_SCOPE)
     elseif(IOS)
         set(${result} "ios" PARENT_SCOPE)
+    elseif(FREEBSD)
+        set(${result} "freebsd" PARENT_SCOPE)
     else()
         message(DEBUG "Unrecognized OS")
     endif()
@@ -804,6 +806,8 @@ macro(append_build_type_setup)
         use_allocator="none"
         use_custom_libcxx=false
     )
+    # XXX Check if this needs to be adjusted, e.g setting symbol_level=1
+    #     if too much memory is required for a debug build.
     if(${config} STREQUAL "Debug")
         list(APPEND gnArgArg is_debug=true symbol_level=2)
         if(WIN32)
@@ -852,9 +856,10 @@ macro(append_build_type_setup)
         endif()
     endif()
 
+    # XXX Check - Does it make sense to expose this?
     extend_gn_list(gnArgArg
         ARGS enable_precompiled_headers
-        CONDITION BUILD_WITH_PCH AND NOT LINUX
+	CONDITION BUILD_WITH_PCH AND NOT (LINUX OR FREEBSD)
     )
     extend_gn_list(gnArgArg
         ARGS dcheck_always_on
@@ -902,7 +907,8 @@ macro(append_compiler_linker_sdk_setup)
                 use_libcxx=true
             )
         endif()
-        if(DEFINED QT_FEATURE_stdlib_libcpp AND LINUX)
+	# XXX Check - Does it make sense to expose it?
+	if(DEFINED QT_FEATURE_stdlib_libcpp AND (LINUX OR FREEBSD))
             extend_gn_list(gnArgArg ARGS use_libcxx
                 CONDITION QT_FEATURE_stdlib_libcpp
             )
@@ -930,7 +936,8 @@ macro(append_compiler_linker_sdk_setup)
         )
     endif()
     get_gn_arch(cpu ${TEST_architecture_arch})
-    if(LINUX AND CMAKE_CROSSCOMPILING AND cpu STREQUAL "arm")
+    # XXX Check - might be relevant for arm64, armv6, armv7 ...
+    if((LINUX OR FREEBSD) AND CMAKE_CROSSCOMPILING AND cpu STREQUAL "arm")
 
         extend_gn_list_cflag(gnArgArg
             ARG arm_tune
@@ -997,7 +1004,7 @@ macro(append_toolchain_setup)
 endmacro()
 
 macro(append_toolchain_setup)
-    if(LINUX)
+    if(LINUX OR FREEBSD)
         list(APPEND gnArgArg
             custom_toolchain="${buildDir}/target_toolchain:target"
             host_toolchain="${buildDir}/host_toolchain:host"
@@ -1024,7 +1031,7 @@ macro(append_pkg_config_setup)
 
 
 macro(append_pkg_config_setup)
-    if(LINUX)
+    if(LINUX OR FREEBSD)
         list(APPEND gnArgArg
             pkg_config="${PKG_CONFIG_EXECUTABLE}"
             host_pkg_config="${PKG_CONFIG_HOST_EXECUTABLE}"
@@ -1100,6 +1107,20 @@ function(add_gn_build_aritfacts_to_target cmakeTarget 
             set_target_properties(${cmakeTarget} PROPERTIES
                 LINK_DEPENDS ${buildDir}/${config}/${arch}/${ninjaTarget}.stamp
             )
+            # For some reason when the build of QtWebEngine's "convert_dict" is
+            # completed the "convert_dict.stamp" isn't created.
+            #
+            # Work around this issue by creating "convert_dict.stamp" manually.
+            if(${ninjaTarget} STREQUAL "convert_dict")
+                add_custom_command(
+                    POST_BUILD
+                    COMMENT "Add workaround for missing ${ninjaTarget}.stamp file after build"
+                    COMMAND ${CMAKE_COMMAND} -E touch ${buildDir}/${config}/${arch}/${ninjaTarget}.stamp
+                    TARGET ${target}
+                    DEPENDS run_${module}_NinjaDone
+                    USES_TERMINAL
+            )
+            endif()
             if(QT_IS_MACOS_UNIVERSAL)
                 add_intermediate_archive(${target} ${buildDir}/${config}/${arch} ${completeStatic})
             elseif(IOS)
@@ -1222,7 +1243,7 @@ function(check_for_ulimit)
 
 function(check_for_ulimit)
     message("-- Checking 'ulimit -n'")
-    execute_process(COMMAND bash -c "ulimit -n"
+    execute_process(COMMAND sh -c "ulimit -n"
         OUTPUT_VARIABLE ulimitOutput
     )
     string(REGEX MATCHALL "[0-9]+" limit "${ulimitOutput}")
@@ -1231,7 +1252,7 @@ function(check_for_ulimit)
         if(NOT ${CMAKE_VERSION} VERSION_LESS "3.21.0")
             message(" -- Creating linker launcher")
             file(GENERATE OUTPUT ${PROJECT_BINARY_DIR}/linker_ulimit.sh
-                CONTENT "#!/bin/bash\nulimit -n 4096\nexec \"$@\""
+                CONTENT "#!/bin/sh\nulimit -n 4096\nexec \"$@\""
                 FILE_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
             )
             set(COIN_BUG_699 ON PARENT_SCOPE)
