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

TEST(Vector, Constructor) {
  Vector v1(1.0f, 0.0f, 0.5f);
  Vector v2(1.0f, 0.0f, 0.5f);
  ASSERT_EQ(v1, v2);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
