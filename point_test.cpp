#include <gtest/gtest.h>
#include "point.cpp"

TEST(Point, Equality) {
  Point v1(1.f, 0.f, 0.5f);
  Point v2(1.f, 0.f, 0.5f);
  ASSERT_EQ(v1, v2);
}

TEST(Point, Addition) {
  Point lhs(0.2f, 0.3f, 0.1f);
  Point rhs(0.3f, 0.2f, 0.f);
  Vector sum(0.5f, 0.5f, 0.1f);
  ASSERT_EQ(lhs+rhs, sum);
}

TEST(Point, Subtraction) {
  Point lhs(0.4f, 0.3f, 0.2f);
  Point rhs(0.3f, 0.2f, 0.1f);
  Vector res(0.1f, 0.1f, 0.1f);
  ASSERT_TRUE(lhs-rhs==res);
}
