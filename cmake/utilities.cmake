macro(generate_pkgconfig_link_flags LIBS_LIST OUTPUT_VAR)
    set(${OUTPUT_VAR} "")
    foreach(LIB IN LISTS ${LIBS_LIST})
        if(${OUTPUT_VAR})
            set(${OUTPUT_VAR} "${${OUTPUT_VAR}} -l${LIB}")
        else()
            set(${OUTPUT_VAR} "-l${LIB}")
        endif()
    endforeach()
endmacro()

# this function is based on the unity build function described at: https://cheind.wordpress.com/2009/12/10/reducing-compilation-time-unity-builds/
function(enable_unity_build UNITY_SUFFIX SOURCE_FILES)
    set(files ${${SOURCE_FILES}})

    # Generate a unique filename for the unity build translation unit
    set(unity_build_file ${CMAKE_CURRENT_BINARY_DIR}/ub_${UNITY_SUFFIX}.cpp)

    # Exclude all translation units from compilation
    set_source_files_properties(${files} PROPERTIES HEADER_FILE_ONLY true)

    # Open the ub file
    FILE(WRITE ${unity_build_file} "// Unity Build generated by CMake\n")

    # Add include statement for each translation unit
    foreach(source_file ${files} )
        FILE( APPEND ${unity_build_file} "#include <${source_file}>\n")
    endforeach(source_file)

    # Complement list of translation units with the name of ub
    set(${SOURCE_FILES} ${${SOURCE_FILES}} ${unity_build_file} PARENT_SCOPE)
endfunction(enable_unity_build)

macro(setup_install)
    if(SIMPLE_INSTALL)
        configure_file("${AWS_NATIVE_SDK_ROOT}/toolchains/pkg-config.pc.in" "${PROJECT_NAME}.pc" @ONLY)

        install( TARGETS ${PROJECT_NAME}
                EXPORT "${PROJECT_NAME}-targets"
                ARCHIVE DESTINATION ${ARCHIVE_DIRECTORY}
                LIBRARY DESTINATION ${LIBRARY_DIRECTORY}
                RUNTIME DESTINATION ${BINARY_DIRECTORY} )

        if (BUILD_SHARED_LIBS)
            install(
                FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc"
                DESTINATION ${LIBRARY_DIRECTORY}/pkgconfig)
        endif()
    else()
        if(PLATFORM_CUSTOM)
            install_custom_library(${PROJECT_NAME})
        else()
            install (TARGETS ${PROJECT_NAME}
                     ARCHIVE DESTINATION ${ARCHIVE_DIRECTORY}/${SDK_INSTALL_BINARY_PREFIX}/${PLATFORM_INSTALL_QUALIFIER}/\${CMAKE_INSTALL_CONFIG_NAME}
                     LIBRARY DESTINATION ${LIBRARY_DIRECTORY}/${SDK_INSTALL_BINARY_PREFIX}/${PLATFORM_INSTALL_QUALIFIER}/\${CMAKE_INSTALL_CONFIG_NAME}
                     RUNTIME DESTINATION ${BINARY_DIRECTORY}/${SDK_INSTALL_BINARY_PREFIX}/${PLATFORM_INSTALL_QUALIFIER}/\${CMAKE_INSTALL_CONFIG_NAME})
        endif()
    endif()
endmacro()

macro(do_packaging)
    if(SIMPLE_INSTALL)
        write_basic_package_version_file(
            "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake"
            VERSION ${PROJECT_VERSION}
            COMPATIBILITY AnyNewerVersion
        )

        export(EXPORT "${PROJECT_NAME}-targets"
            FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-targets.cmake"
            NAMESPACE AWS::
        )

    if(${PROJECT_NAME} STREQUAL "aws-cpp-sdk-core")
        configure_file(
            "${AWS_NATIVE_SDK_ROOT}/toolchains/core-config.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
            @ONLY)
    else()
        configure_file(
            "${AWS_NATIVE_SDK_ROOT}/toolchains/cmakeProjectConfig.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
            @ONLY)
    endif()

        set(ConfigPackageLocation "${LIBRARY_DIRECTORY}/cmake/${PROJECT_NAME}")
        install(EXPORT "${PROJECT_NAME}-targets"
            FILE "${PROJECT_NAME}-targets.cmake"
            NAMESPACE AWS::
            DESTINATION ${ConfigPackageLocation}
        )

        install(
            FILES
            "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake"
            DESTINATION
            ${ConfigPackageLocation}
            COMPONENT
            Devel)
    endif()
endmacro()


