cmake_minimum_required(VERSION 3.16)
project(CppPythonEmbed)

set(CMAKE_CXX_STANDARD 17)

# Locate Python
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

include_directories(${Python3_INCLUDE_DIRS})

add_executable(cpp_python_embed main.cpp)

target_link_libraries(cpp_python_embed ${Python3_LIBRARIES})
