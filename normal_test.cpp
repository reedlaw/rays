#include <gtest/gtest.h>
#include "normal.cpp"

TEST(Normal, Constructor) {
  Normal vec(1.5f, -2.0f, 0.5f);
  Normal normal(1.0f, 1.0f, 0.5f);
  ASSERT_EQ(normal, vec);
}

TEST(Normal, Equality) {
  Normal v1(1.0f, 0.0f, 0.5f);
  Normal v2(1.0f, 0.0f, 0.5f);
  ASSERT_EQ(v1, v2);
}

TEST(Normal, Addition) {
  Normal lhs(0.2f, 0.3f, 0.1f);
  Normal rhs(0.3f, 0.2f, 0.0f);
  Normal sum(0.5f, 0.5f, 0.1f);
  ASSERT_EQ(lhs+rhs, sum);
}

TEST(Normal, Subtraction) {
  Normal lhs(0.4f, 0.3f, 0.2f);
  Normal rhs(-0.3f, 0.2f, 0.1f);
  Normal res(0.1f, 0.1f, 0.1f);
  ASSERT_TRUE(lhs-rhs==res);
}

TEST(Normal, ScalarMultiplication) {
  Normal vec(0.2f, 0.4f, 0.1f);
  float scalar = 2.0f;
  Normal multiplied(0.4f, 0.8f, 0.2f);
  ASSERT_EQ(vec*scalar, multiplied);
}

TEST(Normal, ScalarDivision) {
  Normal vec(0.2f, 0.4f, 0.1f);
  float scalar = 2.0f;
  Normal divided(0.1f, 0.2f, 0.05f);
  ASSERT_EQ(vec/scalar, divided);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
