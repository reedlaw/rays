class World {
public:
  std::vector<Primitive*> primitives;
  std::vector<Light> lights;
  Color ambient;
  bool intersect(Ray& ray, Intersection& intersection);
  bool isVisible(Light& light, Intersection& intersection);
  Color illuminationModel(Intersection& intersection);
};

bool World::intersect(Ray& ray, Intersection& intersection) {
  float minDistance = 1000000.f;
  bool isHit = false;
  LocalGeometry local = LocalGeometry();
  for(int i=0; i < primitives.size(); i++) {
    if (primitives[i]->intersect(ray, local)) {
      if (ray.t > 0 && ray.t < minDistance) {
        minDistance = ray.t;
        isHit = true;
        intersection.primitive = primitives[i];
        intersection.local = local;
      }
    }
  }
  return isHit;
}

bool World::isVisible(Light& light, Intersection& intersection) {
  Ray shadowRay = light.generateShadowRay(intersection.local.position);
  for(int j=0; j < primitives.size(); j++) {
    if (primitives[j]->isIntersected(shadowRay)) {
      return false;
    }
  }
  return true;
}

Color World::illuminationModel(Intersection& intersection) {
  Color totalColor(0.f, 0.f, 0.f);
  for(int i=0; i < lights.size(); i++) {
    if (isVisible(lights[i], intersection)) {
      float normalDotDirection = intersection.local.normal * lights[i].position;
      Material material = intersection.primitive->getMaterial();
      Color diffuse = lights[i].color * std::max(normalDotDirection, 0.f);
      totalColor = totalColor + diffuse;
    }
  }
  totalColor = totalColor + ambient;
  return totalColor;
}
