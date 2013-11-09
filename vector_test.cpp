#include <gtest/gtest.h>
#include "vector.cpp"

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

TEST(Vector, ScalarMultiplication) {
  Vector vec(0.2f, 0.4f, 0.1f);
  float scalar = 2.0f;
  Vector multiplied(0.4f, 0.8f, 0.2f);
  ASSERT_EQ(vec*scalar, multiplied);
}

TEST(Vector, ScalarDivision) {
  Vector vec(0.2f, 0.4f, 0.1f);
  float scalar = 2.0f;
  Vector divided(0.1f, 0.2f, 0.05f);
  ASSERT_EQ(vec/scalar, divided);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
