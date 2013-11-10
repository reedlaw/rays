#include <cstdio>
#include "vector.cpp"
#include "point.cpp"
#include "normal.cpp"
#include "ray.cpp"
#include "matrix.cpp"
#include "transformation.cpp"
#include "color.cpp"
#include "brdf.cpp"
#include "sample.cpp"
#include "sampler.cpp"
#include "shape.cpp"
#include "camera.cpp"
#include "parser.cpp"
#include "film.cpp"

Sampler sampler;
Film film;

void render(const Parser parser) {
  int w = parser.width;
  int h = parser.height;
  Camera camera = parser.camera;
  film.init(w, h);
  for (int i=0; i<w; i++) {
    for (int j=0; j<h; j++) {
      Sample sample(i, j);
      Color color(1.0f, 0.0f, 0.0f);
      Ray ray;
      camera.generateRay(sample, &ray);
      // raytracer.trace(ray, &color);
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

