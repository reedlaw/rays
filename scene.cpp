#define T_MIN 0.01f
#define T_MAX 1000000000.f

#include <cstdio>
#include <vector>
#include <algorithm>
#include "vector.cpp"
#include "point.cpp"
#include "normal.cpp"
#include "ray.cpp"
#include "matrix.cpp"
#include "transformation.cpp"
#include "color.cpp"
#include "material.cpp"
#include "light.cpp"
#include "sample.cpp"
#include "sampler.cpp"
#include "local_geometry.cpp"
#include "primitive.cpp"
#include "intersection.cpp"
#include "sphere.cpp"
#include "world.cpp"
#include "camera.cpp"
#include "parser.cpp"
#include "film.cpp"
#include "ray_tracer.cpp"

Sampler sampler;
Film film;

void render(const Parser parser) {
  int w = parser.width;
  int h = parser.height;
  Camera camera = parser.camera;
  RayTracer rayTracer(parser.world);
  film.init(w, h);
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      Sample sample(i, j);
      Color color(0.0f, 0.0f, 0.0f);
      Ray ray;
      camera.generateRay(sample, &ray);
      rayTracer.trace(ray, &color);
      film.commit(sample, color);
    }
  }
  film.writeImage();
}

int main(int argc, char **argv) {
  Parser parser(argv[1]);
  parser.parse();
  render(parser);
}

