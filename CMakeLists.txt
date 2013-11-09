cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Main program
add_executable(rays scene.cpp)

# Link tests with what we want to test and the GTest and pthread library
add_executable(vector_test vector_test.cpp)
target_link_libraries(vector_test ${GTEST_LIBRARIES} pthread)

add_executable(normal_test normal_test.cpp)
target_link_libraries(normal_test ${GTEST_LIBRARIES} pthread)
