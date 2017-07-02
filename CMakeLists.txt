cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "-Wall -pedantic -Wextra")

SET( EIGEN3_INCLUDE_DIR "Eigen" )
INCLUDE_DIRECTORIES ( "${EIGEN3_INCLUDE_DIR}")
INCLUDE_DIRECTORIES (src)


project (MLcpp)

set(MLcpp_VERSION_MAJOR 1)
set(MLcpp_VERSION_MINOR 0)

add_executable(MLcpp test.cpp)
