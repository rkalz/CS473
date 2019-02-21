cmake_minimum_required(VERSION 3.13)
project(hw4)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
add_definitions(-DPROJECT_DIR="${CMAKE_SOURCE_DIR}")

add_executable(hw4 main.cc sobel_gradient.cc mat_math.cc)
target_link_libraries(hw4 ${OpenCV_LIBS} )