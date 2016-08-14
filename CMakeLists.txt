cmake_minimum_required(VERSION 2.8)

# ┌──────────────────────────────────────────────────────────────────┐
# │  VARIABLE POOL                                                   │
# └──────────────────────────────────────────────────────────────────┘
set(GLFW_SOURCE_DIR "lib/glfw")
file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*)


# ┌──────────────────────────────────────────────────────────────────┐
# │  GLFW                                                            │
# └──────────────────────────────────────────────────────────────────┘
set(BUILD_SHARED_LIBS OFF CACHE BOOL "")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
set(GLFW_INSTALL OFF CACHE BOOL "")
add_subdirectory(${GLFW_SOURCE_DIR})
include_directories(${GLFW_SOURCE_DIR}/include ${GLFW_SOURCE_DIR}/deps)

# ┌──────────────────────────────────────────────────────────────────┐
# │  FLAGS                                                           │
# └──────────────────────────────────────────────────────────────────┘
# C++ 11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
# Linker
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework IOKit")

# ┌──────────────────────────────────────────────────────────────────┐
# │  APPLE CLAUSE                                                    │
# └──────────────────────────────────────────────────────────────────┘
if (APPLE)
    set(APP_NAME "glfw-cmake-boilerplate")

    if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/icon.icns)
        add_executable(${APP_NAME} MACOSX_BUNDLE main.cpp icon.icns)
        set_source_files_properties("icon.icns" PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
        set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_ICON_FILE ${CMAKE_CURRENT_SOURCE_DIR}/icon.icns)
    else ()

        add_executable(${APP_NAME} MACOSX_BUNDLE ${SOURCE_FILES})
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

# ┌──────────────────────────────────────────────────────────────────┐
# │  LINK LIBRARIES                                                  │
# └──────────────────────────────────────────────────────────────────┘
target_link_libraries(${APP_NAME} glfw ${GLFW_LIBRARIES})

# ┌──────────────────────────────────────────────────────────────────┐
# │  POST BUILD COMMANDS                                             │
# └──────────────────────────────────────────────────────────────────┘
add_custom_target(run
    COMMAND open glfw-cmake-boilerplate.app
)
