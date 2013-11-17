#include <gtest/gtest.h>
#include "intersection.cpp"
#include "world.cpp"

TEST(World, IntersectPositive) {
  Vector pos = Vector(0.f, 0.f, -4.f);
  Vector dir = Vector(0.f, 0.f, 1.f);
  Ray ray = Ray(pos, dir, T_MIN, T_MAX);
  Sphere sphere = Sphere(Vector(0.f, 0.f, 0.f), 0.15f);
  World world;
  world.spheres.push_back(sphere);
  Intersection intersection =  Intersection();
  ASSERT_TRUE(world.intersect(ray, intersection));
}

TEST(World, IsVisiblePositive) {
  World world;
  world.spheres.push_back(Sphere(Vector(0.f, 0.f, 0.f), 0.15f));
  world.lights.push_back(Light(Vector(0.f, 5.f, 0.f), Color(1.f, 1.f, 1.f)));
  Vector eye = Vector(0.f, 0.f, 0.f);
  Vector lookAt = Vector(0.f, 0.f, -1.f);
  Ray cameraRay = Ray(eye, lookAt, T_MIN, T_MAX);
  Intersection intersection =  Intersection();
  world.intersect(cameraRay, intersection);
  ASSERT_TRUE(world.isVisible(intersection));
}

TEST(World, IsVisibleNegative) {
  World world;
  world.spheres.push_back(Sphere(Vector(0.f, 0.f, 0.f), 0.15f));
  world.spheres.push_back(Sphere(Vector(0.f, 1.f, 0.f), 0.15f));
  world.lights.push_back(Light(Vector(0.f, 5.f, 0.f), Color(1.f, 1.f, 1.f)));
  Vector eye = Vector(0.f, 0.f, 0.f);
  Vector lookAt = Vector(0.f, 0.f, -1.f);
  Ray cameraRay = Ray(eye, lookAt, T_MIN, T_MAX);
  Intersection intersection =  Intersection();
  world.intersect(cameraRay, intersection);
  ASSERT_FALSE(world.isVisible(intersection));
}
