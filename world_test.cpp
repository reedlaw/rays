#include <gtest/gtest.h>
#include "world.cpp"

TEST(World, FindNearestIntersectionPositive) {
  Vector pos = Vector(0.f, 0.f, -4.f);
  Vector dir = Vector(0.f, -.2f, 0.f);
  Ray ray = Ray(pos, dir, T_MIN, T_MAX);
  Sphere sphere = Sphere(Vector(0.f, 0.f, 0.f), 0.15f);
  World world;
  world.spheres.push_back(sphere);
  ASSERT_TRUE(world.findNearestIntersection(ray));
}

TEST(World, IsVisiblePositive) {
  Vector pos = Vector(0.f, 0.f, 0.f);
  Vector dir = Vector(0.f, 1.f, 0.f);
  Ray ray = Ray(pos, dir, T_MIN, T_MAX);
  Sphere sphere = Sphere(dir, 0.15f);
  sphere.intersect(ray);
  World world;
  Light light(Vector(1.f, 0.f, 0.f), Color(1.f, 1.f, 1.f));
  world.spheres.push_back(sphere);
  world.lights.push_back(light);
  ASSERT_TRUE(world.isVisible());
}

TEST(World, IsVisibleNegative) {
  Vector pos = Vector(0.f, 0.f, 0.f);
  Vector dir = Vector(0.f, 1.f, 0.f);
  Ray ray = Ray(pos, dir, T_MIN, T_MAX);
  Sphere sphere = Sphere(dir, 0.15f);
  sphere.intersect(ray);
  World world;
  Light light(Vector(0.f, 5.f, 0.f), Color(1.f, 1.f, 1.f));
  world.spheres.push_back(sphere);
  world.lights.push_back(light);
  ASSERT_FALSE(world.isVisible());
}
