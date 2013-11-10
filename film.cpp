#include <FreeImage.h>
#define BPP 24

class Film {
public:
  int width;
  int height;
  FIBITMAP* bitmap;
  RGBQUAD pixel;

  inline void init(int w, int h) {
    width = w;
    height = h;
    FreeImage_Initialise();
    bitmap = FreeImage_Allocate(w, h, BPP);
  }

  // Will write the color to (sample.x, sample.y) on the image
  void commit(Sample& sample, Color& color);
  // Output image to a file
  void writeImage();
};

void Film::commit(Sample& sample, Color& color) {
  pixel.rgbRed = color.r;
  pixel.rgbGreen = color.g;
  pixel.rgbBlue = color.b;
  FreeImage_SetPixelColor(bitmap, sample.x, sample.y, &pixel);
}

void Film::writeImage() {
  FreeImage_Save(FIF_PNG, bitmap, "image.png", 0);
  FreeImage_DeInitialise();
}
