cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_FLAGS "-g -Wall -pedantic -Wextra")
message("CMAKE_CXX_FLAGS is ${CMAKE_CXX_FLAGS}")

SET( EIGEN3_INCLUDE_DIR "Eigen" )
IF( NOT EIGEN3_INCLUDE_DIR )
    MESSAGE( FATAL_ERROR "Please point the environment variable EIGEN3_INCLUDE_DIR to the include directory of your Eigen3 installation.")
ENDIF()
INCLUDE_DIRECTORIES ( "${EIGEN3_INCLUDE_DIR}" )


project (MLcpp)

set (MLcpp_VERSION_MAJOR 1)
set (MLcpp_VERSION_MINOR 0)


add_executable(MLcpp test.cpp)
