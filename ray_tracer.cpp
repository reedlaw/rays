class RayTracer {
public:
  World world;

  RayTracer(World w) {
    world = w;
  }
  void trace(Ray& ray, Color* color);
};

void RayTracer::trace(Ray& ray, Color* color) {
  Color black = Color(0.f, 0.f, 0.f);
  if (world.findNearestIntersection(ray)) {
    float r = (ray.t * 100.f + 140.f)/10;
    *color = world.isVisible() ? world.illuminationModel() : Color(0.f, 1.f, 0.f);
  } else {
    *color = black;
  }
}
