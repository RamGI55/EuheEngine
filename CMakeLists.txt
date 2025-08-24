cmake_minimum_required(VERSION 3.31)
project(EuheEngine)

set(CMAKE_CXX_STANDARD 20)

if(NOT DEFINED OPENGL_PATH)
    message(FATAL_ERROR "OPENGL_PATH is not set. Pass it via -DOPENGL_PATH=...")
endif()

if(NOT DEFINED GLAD_PATH)
    message(FATAL_ERROR "GLAD_PATH is not set. Pass it via -DGLAD_PATH=...")
endif()

include_directories(${GLAD_PATH}/include)
include_directories(${OPENGL_PATH}/include)
link_directories(${OPENGL_PATH}/lib)


add_executable(EuheEngine main.cpp
        Euhe.h
        ${GLAD_PATH}/src/glad.c
        Shader.cpp
        Shader.h
        Texture.cpp
        Texture.h)

target_link_libraries(
        EuheEngine
        ${OPENGL_PATH}/lib/libglfw3.a
        opengl32
        gdi32
        user32
        kernel32
)




