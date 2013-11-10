#include "matrix.cpp"

TEST(Matrix, Constructor) {
  float val = 1.f;
  Matrix m(val);
  ASSERT_EQ(m.mat[2][1], 1.f);
  ASSERT_EQ(m.mat[0][0], 1.f);
  ASSERT_EQ(m.mat[3][3], 1.f);
}
