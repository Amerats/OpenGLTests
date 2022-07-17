cmake_minimum_required(VERSION 3.22)
project(OpenGLTests)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread -fpermissive")

find_package (OpenGL REQUIRED)
find_package (GLUT REQUIRED)


set(CMAKE_CXX_STANDARD 14)

add_executable(OpenGLTests main.cpp Ground.cpp Ground.h Vector3.cpp Vector3.h)

target_link_libraries(OpenGLTests ${OPENGL_LIBRARIES})
target_link_libraries(OpenGLTests ${GLUT_LIBRARIES})
target_link_libraries(OpenGLTests -lopengl32 -g -lfreeglut)
