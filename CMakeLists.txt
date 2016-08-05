cmake_minimum_required(VERSION 3.5)
project("glfw-cmake-boilerplate")

# Disable GLFW Builds
set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Add GLFW Root Directory
add_subdirectory(libs/glfw)

# Include source files
# include_directories(src)

# Link-time deps / Include dirs / (GLFW_DLL macro)
#target_link_libraries(glfw-cmake-boilerplate glfw)

# Note: does not include GLU (unused in GLFW)
#       -> you can find it by requiring OpenGL package
#find_package(OpenGL REQUIRED)
# When GLU is found the "OPENGL_GLU_FOUND" variable is true
# and the "OPENGL_INCLUDE_DIR" & "OPENGL_glu_LIBRARY" cache variables can be used
#target_include_directories(glfw-cmake-boilerplate ${OPENGL_INCLUDE_DIR})
#target_link_libraries(glfw-cmake-boilerplate ${OPENGL_glu_LIBRARY})

# ┌──────────────────────────────────────────────────────────────────┐
# │  Build executable                                                │
# └──────────────────────────────────────────────────────────────────┘
file(GLOB_RECURSE source_files ${PROJECT_SOURCE_DIR}/src/*)
add_executable(main ${source_files})
target_link_libraries(main glfw ${GLFW_LIBRARIES} )

# ┌──────────────────────────────────────────────────────────────────┐
# │  POST build                                                      │
# └──────────────────────────────────────────────────────────────────┘
add_custom_target(run
    COMMAND open main && quit
)
