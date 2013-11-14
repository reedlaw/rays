#include <gtest/gtest.h>
#include "sample.cpp"
#include "camera.cpp"

TEST(Camera, getAlpha) {
  Camera camera(Vector(-1.f, 0.f, 0.f), Vector(1.f, 0.f, 0.f),
                Vector(0.f, 1.f, 0.f), 30.f, 100.f, 100.f);
  ASSERT_FLOAT_EQ(camera.getAlpha(100), 0.267949192f);
}

TEST(Camera, getBeta) {
  Camera camera(Vector(-1.f, 0.f, 0.f), Vector(1.f, 0.f, 0.f),
                Vector(0.f, 1.f, 0.f), 30.f, 100.f, 100.f);
  ASSERT_FLOAT_EQ(camera.getBeta(0), 0.267949192f);
}
