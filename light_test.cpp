#include <gtest/gtest.h>
#include "light.cpp"

TEST(Light, GeneratesRay) {
  Vector localPoint(0.f, 0.f, 0.f);
  Light light(Vector(0.f, 0.f, 5.f), Color(.5f, .5f, .5f));
  light.generateLightRay(localPoint);
  ASSERT_EQ(light.shadowRay.position, Vector(0.f, 0.f, 0.0005f));
  ASSERT_EQ(light.shadowRay.direction, Vector(0.f, 0.f, 5.f));
}
