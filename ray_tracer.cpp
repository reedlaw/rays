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
  Intersection intersection =  Intersection();
  if (world.intersect(ray, intersection)) {
    *color = world.illuminationModel(intersection);
  } else {
    *color = black;
  }
}
