#include <gtest/gtest.h>
#include "vector.cpp"

void render() {
  // while (!sampler.generateSample(&sample)) {
  //   camera.generateRay(sample, &ray);
  //   raytracer.trace(ray, &color);
  //   film.commit(sample, color);
  // }
  // film.writeImage();
}

TEST(Render, Positive) {
  ASSERT_EQ(1, 1);
}

TEST(Vector, Equality) {
  Vector v1(1.0f, 0.0f, 0.5f);
  Vector v2(1.0f, 0.0f, 0.5f);
  ASSERT_EQ(v1, v2);
}

TEST(Vector, Addition) {
  Vector lhs(0.2f, 0.3f, 0.1f);
  Vector rhs(0.3f, 0.2f, 0.0f);
  Vector sum(0.5f, 0.5f, 0.1f);
  ASSERT_EQ(lhs+rhs, sum);
}

TEST(Vector, Subtraction) {
  Vector lhs(0.4f, 0.3f, 0.2f);
  Vector rhs(0.3f, 0.2f, 0.1f);
  Vector res(0.1f, 0.1f, 0.1f);
  Vector result = lhs-rhs;
  ASSERT_TRUE(lhs-rhs==res);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
