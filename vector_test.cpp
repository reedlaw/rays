#include <gtest/gtest.h>
#include "vector.cpp"

TEST(Vector, Equality) {
  Vector v1(1.f, 0.f, 0.5f);
  Vector v2(1.f, 0.f, 0.5f);
  ASSERT_EQ(v1, v2);
}

TEST(Vector, Addition) {
  Vector lhs(0.2f, 0.3f, 0.1f);
  Vector rhs(0.3f, 0.2f, 0.f);
  Vector sum(0.5f, 0.5f, 0.1f);
  ASSERT_EQ(lhs+rhs, sum);
}

TEST(Vector, Subtraction) {
  Vector lhs(0.4f, 0.3f, 0.2f);
  Vector rhs(0.3f, 0.2f, 0.1f);
  Vector res(0.1f, 0.1f, 0.1f);
  ASSERT_TRUE(lhs-rhs==res);
}

TEST(Vector, ScalarMultiplication) {
  Vector vec(0.2f, 0.4f, 0.1f);
  float scalar = 2.f;
  Vector multiplied(0.4f, 0.8f, 0.2f);
  ASSERT_EQ(vec*scalar, multiplied);
}

TEST(Vector, ScalarDivision) {
  Vector vec(0.2f, 0.4f, 0.1f);
  float scalar = 2.f;
  Vector divided(0.1f, 0.2f, 0.05f);
  ASSERT_EQ(vec/scalar, divided);
}

TEST(Vector, CrossProduct1) {
  Vector vec1(0.5f,0.f,0.5f);
  Vector vec2(0.0f,0.5f,0.f);
  Vector result(-0.25,0.f,0.25f);
  Vector cross = Vector::cross(vec1, vec2);
  ASSERT_EQ(cross, result);
}

TEST(Vector, CrossProduct2) {
  Vector vec1(1.f,2.f,3.f);
  Vector vec2(-3.f,2.f,-1.f);
  Vector result(-8.f,-8.f,8.f);
  Vector cross = Vector::cross(vec1, vec2);
  ASSERT_EQ(cross, result);
}

TEST(Vector, DotProduct) {
  Vector v(-4.f,-4.f,4.f);
  float dotProduct = v*v;
  ASSERT_EQ(48.f, dotProduct);
}

TEST(Vector, Normalization) {
  Vector vec(3.f, 1.f, 2.f);
  Vector norm = vec.normalize();
  Vector result(0.80178368091583252f, 0.26726123690605164f, 0.53452247381210327f);
  ASSERT_EQ(norm, result) << "Vectors differ x " << norm.x << " y " << norm.y << " z " << norm.z;
}

TEST(Vector, NormalizationOfZeroVector) {
  Vector zero(0.f, 0.f, 0.f);
  ASSERT_THROW(zero.normalize(), int);
}
