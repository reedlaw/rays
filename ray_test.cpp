#include <gtest/gtest.h>
#include "ray.cpp"
TEST(Ray, GetPoint1) {
  Vector pos(0.f, 0.707106781f, 3.f);
  Vector dir(0.f, 0.f, -1.f);
  Ray ray(pos, dir, 0.f, 10000.f);
  ray.t = 2.292893219f;
  Vector point(0.f, 0.707106781f, 0.707106781f);
  ASSERT_EQ(ray.getPoint(), point);
}

TEST(Ray, GetPoint2) {
  Vector pos(0.f, 0.f, 3.f);
  Vector dir(0.f, 0.f, -1.f);
  Ray ray(pos, dir, 0.f, 10000.f);
  ray.t = 2.f;
  Vector point(0.f, 0.f, 1.f);
  ASSERT_EQ(ray.getPoint(), point);
}
