#include <gtest/gtest.h>

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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
