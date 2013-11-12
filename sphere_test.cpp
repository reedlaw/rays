#include <gtest/gtest.h>
#include "ray.cpp"
#include "sphere.cpp"

TEST(Sphere, Intersection) {
  Vector pos = Vector(0.f, 0.f, 0.f);
  Vector dir = Vector(0.f, 1.f, 0.f);
  Ray ray = Ray(pos, dir, 0.1f, 10000.f);
  Sphere sphere = Sphere(dir, 0.15f);
  ASSERT_TRUE(sphere.intersect(ray));
}

TEST(Sphere, IntersectionTangent) {
  Vector pos = Vector(0.f, 0.f, 0.f);
  Vector dir = Vector(0.15f, 1.f, 0.f);
  Ray ray = Ray(pos, dir, 0.1f, 10000.f);
  Vector center = Vector(0.f, 1.f, 0.f);
  Sphere sphere = Sphere(center, 0.15f);
  ASSERT_TRUE(sphere.intersect(ray));
}

TEST(Sphere, IntersectionTangentNegative) {
  Vector pos = Vector(0.f, 0.f, 0.f);
  Vector dir = Vector(0.16f, 1.f, 0.f);
  Ray ray = Ray(pos, dir, 0.1f, 10000.f);
  Vector center = Vector(0.f, 1.f, 0.f);
  Sphere sphere = Sphere(center, 0.15f);
  ASSERT_FALSE(sphere.intersect(ray));
}

TEST(Sphere, IntersectionNegative) {
  Vector pos = Vector(0.f, 0.f, 0.f);
  Vector dir = Vector(0.f, 1.f, 0.f);
  Ray ray = Ray(pos, dir, 0.1f, 10000.f);
  Sphere sphere = Sphere(Vector(4.f,-5.f,1.f), 0.15f);
  ASSERT_FALSE(sphere.intersect(ray));
}
