cmake_minimum_required(VERSION 3.23)
project(PebbleEngine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)

add_subdirectory(extern/lib/glfw)

add_executable(PebbleEngine
    core/main.cpp
    extern/lib/glad.c
        core/ShaderProgram.h
        core/ShaderProgram.cpp
        core/Shader.h
        core/Shader.cpp
        core/Vertex.h
)

target_include_directories(PebbleEngine
    PRIVATE
        extern/include
)

target_link_libraries(PebbleEngine
    PRIVATE
        glfw
        OpenGL::GL
)

if(UNIX AND NOT APPLE)
    find_package(Threads REQUIRED)
    target_link_libraries(PebbleEngine PRIVATE Threads::Threads X11 dl)
elseif(APPLE)
    target_link_libraries(PebbleEngine PRIVATE
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
    )
endif()