#include <gtest/gtest.h>
#include "sphere.cpp"

TEST(Sphere, Intersection) {
  Vector pos = Vector(0.f, 0.f, 0.f);
  Vector dir = Vector(0.f, 1.f, 0.f);
  Ray ray = Ray(pos, dir, T_MIN, T_MAX);
  Sphere sphere = Sphere(dir, 0.15f);
  ASSERT_TRUE(sphere.intersect(ray));
}

TEST(Sphere, Intersection2) {
  Vector pos = Vector(0.f, 0.f, -4.f);
  Vector dir = Vector(0.f, 0.f, 1.f);
  Ray ray = Ray(pos, dir, T_MIN, T_MAX);
  Sphere sphere = Sphere(Vector(0.f, 0.f, 0.f), 0.15f);
  ASSERT_TRUE(sphere.intersect(ray));
}

TEST(Sphere, IntersectionTangent) {
  Vector pos = Vector(0.f, 0.f, 0.f);
  Vector dir = Vector(0.15f, 1.f, 0.f);
  Ray ray = Ray(pos, dir, T_MIN, T_MAX);
  Vector center = Vector(0.f, 1.f, 0.f);
  Sphere sphere = Sphere(center, 0.15f);
  ASSERT_TRUE(sphere.intersect(ray));
}

TEST(Sphere, IntersectionTangentNegative) {
  Vector pos = Vector(0.f, 0.f, 0.f);
  Vector dir = Vector(0.16f, 1.f, 0.f);
  Ray ray = Ray(pos, dir, T_MIN, T_MAX);
  Vector center = Vector(0.f, 1.f, 0.f);
  Sphere sphere = Sphere(center, 0.15f);
  ASSERT_FALSE(sphere.intersect(ray));
}

TEST(Sphere, IntersectionNegative) {
  Vector pos = Vector(0.f, 0.f, 0.f);
  Vector dir = Vector(0.f, 1.f, 0.f);
  Ray ray = Ray(pos, dir, T_MIN, T_MAX);
  Sphere sphere = Sphere(Vector(4.f,-5.f,1.f), 0.15f);
  ASSERT_FALSE(sphere.intersect(ray));
}

TEST(Sphere, GetIntersecitonPoint) {
  float a=1.f;
  float b=-2.f;
  float c=1.f;
  float result = 1.f;
  Vector intersection(0.f, 0.f, 0.f);
  ASSERT_EQ(Sphere::getIntersectionPoint(a, b, c), result);
}

TEST(Sphere, GetIntersecitonPointTwoRootsSame) {
  float a=2.f;
  float b=-4.f;
  float c=2.f;
  float result = 1.f;
  ASSERT_EQ(Sphere::getIntersectionPoint(a, b, c), result);
}

TEST(Sphere, GetIntersecitonPointTwoPositiveRoots) {
  float a=1.f;
  float b=-4.f;
  float c=3.f;
  float result = 1.f;
  ASSERT_EQ(Sphere::getIntersectionPoint(a, b, c), result);
}

TEST(Sphere, GetIntersecitonPointOnePositiveOneNegativeRoot) {
  float a=1.f;
  float b=1.f;
  float c=-6.f;
  float result = 2.f;
  ASSERT_EQ(Sphere::getIntersectionPoint(a, b, c), result);
}

TEST(Sphere, CheckIfDiscriminantNegative) {
  float a=4.f;
  float b=4.f;
  float c=2.f;
  ASSERT_FALSE(Sphere::isDiscriminantPositive(a, b, c));
}

TEST(Sphere, CheckIfDiscriminantPositive) {
  float a=1.f;
  float b=4.f;
  float c=2.f;
  ASSERT_TRUE(Sphere::isDiscriminantPositive(a, b, c));
}
