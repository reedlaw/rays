class World {
public:
  std::vector<Sphere> spheres;
  std::vector<Light> lights;
  Sphere lastIntersected;
  bool findNearestIntersection(Ray& ray);
  bool isVisible();
  Color illuminationModel();
};

bool World::findNearestIntersection(Ray& ray) {
  float minDistance = 1000000.f;
  bool isHit = false;
  for(int i=0; i < spheres.size(); i++) {
    if (spheres[i].intersect(ray)) {
      if (ray.t > 0 && ray.t < minDistance) {
        minDistance = ray.t;
        isHit = true;
        lastIntersected = spheres[i];
      }
    }
  }
  return isHit;
}

bool World::isVisible() {
  for(int i=0; i < lights.size(); i++) {
    lights[i].generateLightRay(lastIntersected.intersectionPoint);
    for(int j=0; j < spheres.size(); j++) {
      if (spheres[j].intersect(lights[i].shadowRay)) {
        return false;
      }
    }
  }
  return true;
}

Color World::illuminationModel() {
  return Color(1.f, 0.f, 0.f);
}
