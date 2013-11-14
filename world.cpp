class World {
public:
  std::vector<Sphere> spheres;

  void getNearestIntersection(Ray& ray);
};

void World::getNearestIntersection(Ray& ray) {
  float minDistance = 1000000.f;
  Sphere hitSphere;
  for(int i=0; i < spheres.size(); i++) {
    if (spheres[i].intersect(ray)) {
      if (ray.t > 0 && ray.t < minDistance) {
        minDistance = ray.t;
        hitSphere = spheres[i];
      }
    }
  }
}  

