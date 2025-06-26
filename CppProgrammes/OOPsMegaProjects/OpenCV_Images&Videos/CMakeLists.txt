cmake_minimum_required(VERSION 3.10)
project(OpenCVProject)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(OpenCVProject main.cpp)  

target_link_libraries(OpenCVProject ${OpenCV_LIBS})
