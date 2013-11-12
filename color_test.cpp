#include <gtest/gtest.h>
#include "color.cpp"
TEST(Color, Constructor) {
  Color c(0.5f, 0.4f, 0.3f);
  ASSERT_EQ(c.r, 127) << "Color.r is " << c.r;
  ASSERT_EQ(c.g, 102) << "Color.g is " << c.g;
  ASSERT_EQ(c.b, 76) << "Color.b is " << c.b;
}   
