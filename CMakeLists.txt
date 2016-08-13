cmake_minimum_required(VERSION 2.8)

set(GLFW_SOURCE_DIR "lib/glfw")
file(GLOB_RECURSE source_files ${PROJECT_SOURCE_DIR}/src/*)

# Building only the GLFW lib
set(BUILD_SHARED_LIBS OFF CACHE BOOL "")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
set(GLFW_INSTALL OFF CACHE BOOL "")

add_subdirectory(${GLFW_SOURCE_DIR})

include_directories(${GLFW_SOURCE_DIR}/include ${GLFW_SOURCE_DIR}/deps)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework IOKit")

if (APPLE)
    set(APP_NAME "glfw-cmake-boilerplate")

    if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/icon.icns)
        add_executable(${APP_NAME} MACOSX_BUNDLE main.cpp icon.icns)
        set_source_files_properties("icon.icns" PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
        set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_ICON_FILE ${CMAKE_CURRENT_SOURCE_DIR}/icon.icns)
    else ()

        add_executable(${APP_NAME} MACOSX_BUNDLE ${source_files})
    endif ()

#    set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules/app.plist.in)

    set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME ${APP_NAME})
    set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0")
    set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_LONG_VERSION_STRING "1.0")
    set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_INFO_STRING "OpenGL boilerplate example app")
else()
    set(APP_NAME "glfw-cmake-boilerplate")
    add_executable(${APP_NAME} main.cpp)
endif()

target_link_libraries(${APP_NAME} glfw ${GLFW_LIBRARIES})

# ┌──────────────────────────────────────────────────────────────────┐
# │  POST build                                                      │
# └──────────────────────────────────────────────────────────────────┘
add_custom_target(run
    COMMAND open glfw-cmake-boilerplate.app && quit
)
