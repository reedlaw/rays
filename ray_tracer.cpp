class RayTracer {
public:
  Sphere sphere;

  RayTracer(Sphere s) {
    sphere = s;
  }
  void trace(Ray& ray, Color* color);
};

void RayTracer::trace(Ray& ray, Color* color) {
  if (sphere.intersect(ray)) {
    *color = Color(1.f, 0.f, 0.f);
  } else {
    *color = Color(0.f, 0.f, 0.f);
  }
}
