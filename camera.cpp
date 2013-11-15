#include <math.h>
class Camera {
public:
  Vector lookFrom;
  Vector lookAt;
  Vector up;
  float fovy;
  float fovx;
  int width;
  int height;

  Camera() {
  }
  Camera(Vector lf, Vector la, Vector u, float f, int w, int h) {
    lookFrom = lf;
    lookAt = la;
    up = u;
    width = w;
    height = h;
    int aspect_ratio = width/height;
    fovy = f;
    fovx = fovy * aspect_ratio;
  }
  void generateRay(Sample& sample, Ray* ray);
  float getAlpha(float j);
  float getBeta(float i);
};

void Camera::generateRay(Sample& sample, Ray* ray) {
  Vector a = lookFrom - lookAt;
  Vector b = up;
  Vector w = a.normalize();
  Vector u = Vector::cross(b,w).normalize();
  Vector v = Vector::cross(w,u);
  float alpha = getAlpha(sample.x);
  float beta = getBeta(sample.y);
  Vector direction = lookFrom + ((u*alpha)+(v*beta)-w).normalize();
  *ray = Ray(lookFrom, direction, T_MIN, T_MAX);
}

float Camera::getAlpha(float j) {
  float radians = (fovx * 3.14159265 / 180.0);
  float alpha = (tan(radians/2)) * ( (j-(width/2)) / (width/2) );
  return alpha;
}

float Camera::getBeta(float i) {
  float radians = (fovy * 3.14159265 / 180.0);
  float beta = (tan(radians/2)) * ( ((width/2)-i) / (width/2) );
  return beta;
}
