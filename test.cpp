#include "vector_test.cpp"
#include "point_test.cpp"
#include "normal_test.cpp"
#include "color_test.cpp"
#include "matrix_test.cpp"
#include "sphere_test.cpp"
#include "camera_test.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
