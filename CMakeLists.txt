cmake_minimum_required(VERSION 2.6)

project(Rays)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Main program
add_executable(rays scene.cpp)
target_link_libraries(rays freeimage)

# Link tests with what we want to test and the GTest and pthread library
add_executable(test test.cpp)
target_link_libraries(test ${GTEST_LIBRARIES} pthread)
