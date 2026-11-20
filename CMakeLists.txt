cmake_minimum_required(VERSION 3.20)

project(echoes_of_mars VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(APPLE AND CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
    list(PREPEND CMAKE_PREFIX_PATH "/opt/homebrew")
elseif(APPLE)
    list(PREPEND CMAKE_PREFIX_PATH "/usr/local")
endif()

find_package(SDL3 REQUIRED)

add_library(glad STATIC external/glad/src/gl.c)
target_include_directories(glad PUBLIC external/glad/include)

add_executable(echoes_of_mars
    src/main.cpp
    src/engine/core/Application.cpp
    src/engine/core/Time.cpp
    src/engine/platform/Window.cpp
    src/engine/platform/Input.cpp
    src/engine/render/GraphicsContext.cpp
    src/game/GameApp.cpp
)

target_include_directories(echoes_of_mars PRIVATE src)

target_link_libraries(echoes_of_mars PRIVATE
    SDL3::SDL3
    glad
)

if(APPLE)
    target_link_libraries(echoes_of_mars PRIVATE "-framework OpenGL")
endif()

if(MSVC)
    target_compile_options(echoes_of_mars PRIVATE /W4)
else()
    target_compile_options(echoes_of_mars PRIVATE -Wall -Wextra -Wpedantic)
endif()
