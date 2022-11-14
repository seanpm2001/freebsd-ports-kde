--- cmake/Functions.cmake.orig	2022-09-26 10:05:50 UTC
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
@@ -665,6 +665,8 @@ function(get_gn_os result)
         set(${result} "mac" PARENT_SCOPE)
     elseif(IOS)
         set(${result} "ios" PARENT_SCOPE)
+    elseif(FREEBSD)
+        set(${result} "freebsd" PARENT_SCOPE)
     else()
         message(DEBUG "Unrecognized OS")
     endif()
@@ -802,8 +804,9 @@ macro(append_build_type_setup)
         use_allocator="none"
         use_custom_libcxx=false
     )
+    # XXX Check
     if(${config} STREQUAL "Debug")
-        list(APPEND gnArgArg is_debug=true symbol_level=2)
+        list(APPEND gnArgArg is_debug=true symbol_level=1)
         if(WIN32)
             list(APPEND gnArgArg enable_iterator_debugging=true v8_optimized_debug=false)
         endif()
@@ -850,9 +853,10 @@ macro(append_build_type_setup)
         endif()
     endif()
 
+    # XXX Check
     extend_gn_list(gnArgArg
         ARGS enable_precompiled_headers
-        CONDITION BUILD_WITH_PCH AND NOT LINUX
+	CONDITION BUILD_WITH_PCH AND NOT (LINUX OR FREEBSD)
     )
     extend_gn_list(gnArgArg
         ARGS dcheck_always_on
@@ -900,7 +904,8 @@ macro(append_compiler_linker_sdk_setup)
                 use_libcxx=true
             )
         endif()
-        if(DEFINED QT_FEATURE_stdlib_libcpp AND LINUX)
+	# XXX Check
+	if(DEFINED QT_FEATURE_stdlib_libcpp AND (LINUX OR FREEBSD))
             extend_gn_list(gnArgArg ARGS use_libcxx
                 CONDITION QT_FEATURE_stdlib_libcpp
             )
@@ -928,6 +933,7 @@ macro(append_compiler_linker_sdk_setup)
         )
     endif()
     get_gn_arch(cpu ${TEST_architecture_arch})
+    # XXX Check
     if(LINUX AND CMAKE_CROSSCOMPILING AND cpu STREQUAL "arm")
 
         extend_gn_list_cflag(gnArgArg
@@ -995,7 +1001,7 @@ macro(append_toolchain_setup)
 endmacro()
 
 macro(append_toolchain_setup)
-    if(LINUX)
+    if(LINUX OR FREEBSD)
         list(APPEND gnArgArg
             custom_toolchain="${buildDir}/target_toolchain:target"
             host_toolchain="${buildDir}/host_toolchain:host"
@@ -1022,7 +1028,7 @@ macro(append_pkg_config_setup)
 
 
 macro(append_pkg_config_setup)
-    if(LINUX)
+    if(LINUX OR FREEBSD)
         list(APPEND gnArgArg
             pkg_config="${PKG_CONFIG_EXECUTABLE}"
             host_pkg_config="${PKG_CONFIG_HOST_EXECUTABLE}"
@@ -1220,7 +1226,7 @@ function(check_for_ulimit)
 
 function(check_for_ulimit)
     message("-- Checking 'ulimit -n'")
-    execute_process(COMMAND bash -c "ulimit -n"
+    execute_process(COMMAND sh -c "ulimit -n"
         OUTPUT_VARIABLE ulimitOutput
     )
     string(REGEX MATCHALL "[0-9]+" limit "${ulimitOutput}")
@@ -1229,7 +1235,7 @@ function(check_for_ulimit)
         if(NOT ${CMAKE_VERSION} VERSION_LESS "3.21.0")
             message(" -- Creating linker launcher")
             file(GENERATE OUTPUT ${PROJECT_BINARY_DIR}/linker_ulimit.sh
-                CONTENT "#!/bin/bash\nulimit -n 4096\nexec \"$@\""
+                CONTENT "#!/bin/sh\nulimit -n 4096\nexec \"$@\""
                 FILE_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
             )
             set(COIN_BUG_699 ON PARENT_SCOPE)
