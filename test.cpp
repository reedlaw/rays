#define T_MIN 0.01f
#define T_MAX 1000000000.f

#include "vector_test.cpp"
#include "point_test.cpp"
#include "normal_test.cpp"
#include "color_test.cpp"
#include "ray_test.cpp"
#include "matrix_test.cpp"
#include "sphere_test.cpp"
#include "light_test.cpp"
#include "world_test.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
