class Primitive {
public:
  virtual Material getMaterial() = 0;
  virtual bool intersect(Ray& ray, LocalGeometry& local) = 0;
  virtual bool isIntersected(Ray& ray) = 0;
  // void getBRDF(BRDF* brdf);
};
