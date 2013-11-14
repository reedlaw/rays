class RayTracer {
public:
  World world;

  RayTracer(World w) {
    world = w;
  }
  void trace(Ray& ray, Color* color);
};

void RayTracer::trace(Ray& ray, Color* color) {
  world.getNearestIntersection(ray);
  float red = (ray.t * 100.f + 140.f)/10;
  *color = Color(red, 0.f, 0.f);
}
