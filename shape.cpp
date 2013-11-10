class Shape {
public:
  bool intersect(Ray& ray, float* thit);
  bool intersectP(Ray& ray);
  void getBRDF(BRDF* brdf);
};
