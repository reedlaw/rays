#include <gtest/gtest.h>
#include "normal.cpp"

TEST(Normal, Equality) {
  Normal v1(1.f, 0.f, 0.5f);
  Normal v2(1.f, 0.f, 0.5f);
  ASSERT_EQ(v1, v2);
}

Vector res(0.80178368091583252f, 0.26726123690605164f, 0.53452247381210327f);

TEST(Normal, Addition) {
  Normal lhs(1.f, 0.3f, 0.1f);
  Normal rhs(2.f, 0.7f, 1.9f);
  ASSERT_EQ(lhs+rhs, res) << "Vectors differ x " << res.x << " y " << res.y << " z " << res.z;
}

TEST(Normal, Subtraction) {
  Normal lhs(4.f, 2.f, 5.f);
  Normal rhs(1.f, 1.f, 3.f);
  ASSERT_EQ(lhs-rhs, res) << "Vectors differ x " << res.x << " y " << res.y << " z " << res.z;
}

// TODO test for normalized return values
TEST(Normal, ScalarMultiplication) {
  Normal vec(0.2f, 0.4f, 0.1f);
  float scalar = 2.f;
  Normal multiplied(0.4f, 0.8f, 0.2f);
  ASSERT_EQ(vec*scalar, multiplied);
}

TEST(Normal, ScalarDivision) {
  Normal vec(0.2f, 0.4f, 0.1f);
  float scalar = 2.f;
  Normal divided(0.1f, 0.2f, 0.05f);
  ASSERT_EQ(vec/scalar, divided);
}

TEST(Normal, Normalization) {
  Normal vec(3.f, 1.f, 2.f);
  Vector normalized = vec.normalize();
  Vector result(0.80178368091583252f, 0.26726123690605164f, 0.53452247381210327f);
  ASSERT_EQ(normalized, result) << "Normals differ x " << normalized.x << " y " << normalized.y << " z " << normalized.z;
}

TEST(Normal, NormalizationOfZeroNormal) {
  Normal zero(0.f, 0.f, 0.f);
  ASSERT_THROW(zero.normalize(), int);
}
