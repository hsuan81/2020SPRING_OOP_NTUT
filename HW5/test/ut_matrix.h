#ifndef UT_MATRIX_H
#define UT_MATRIX_H
#include "../src/matrix.h"
#include "../src/math_vector.h"


class MatrixTest : public ::testing::Test { 
protected: 
    void SetUp() override {
      // a
      MathVector a_r1(ar1, 3); 
      MathVector a_r2(ar2, 3);
      a[0] = a_r1;
      a[1] = a_r2;
      //b
      MathVector b_r1(br1, 3);  
      MathVector b_r2(br2, 3);
      b[0] = b_r1;
      b[1] = b_r2;
      //c
      c[0] = a_r2;
      c[1] = a_r2;
      //d
      d[0] = a_r1;
      d[1] = a_r1;
    }
    // a
    int rowa = 2;
    int cola = 3;
    double ar1[3] = {1, 2, 3};
    double ar2[3] = {2, 2, 3};
    MathVector a[2];
    // b
    int rowb = 2;
    int colb = 3;
    double br1[3] = {1, 2, 2};
    double br2[3] = {3, 6, 4};
    MathVector b[2];
    //c
    int rowc = 2;
    int colc = 3;
    MathVector c[2];
    //d
    int rowd = 2;
    int cold = 3;
    MathVector d[2];
};


TEST_F(MatrixTest, Representation) {
  Matrix m(a, rowa, cola);
  ASSERT_NEAR(1, m.at(1, 1), 0.001);
  ASSERT_NEAR(2, m.at(1, 2), 0.001);
  ASSERT_NEAR(3, m.at(1, 3), 0.001);
  ASSERT_NEAR(2, m.at(2, 1), 0.001);
  ASSERT_NEAR(2, m.at(2, 2), 0.001);
  ASSERT_NEAR(3, m.at(2, 3), 0.001);
}


TEST_F(MatrixTest, Representation_exception) {
  ASSERT_ANY_THROW(Matrix m(a, rowa, rowa));
}

TEST_F(MatrixTest, CopyConstructor) {
  Matrix m(a, rowa, cola);
  Matrix n(m);
  ASSERT_NEAR(1, n.at(1, 1), 0.001);
  ASSERT_NEAR(2, n.at(1, 2), 0.001);
  ASSERT_NEAR(3, n.at(1, 3), 0.001);
  ASSERT_NEAR(2, n.at(2, 1), 0.001);
  ASSERT_NEAR(2, n.at(2, 2), 0.001);
  ASSERT_NEAR(3, n.at(2, 3), 0.001);
}

TEST_F(MatrixTest, GetElement) {
  Matrix m(b, rowb, colb);
  ASSERT_NEAR(1, m.at(1, 1), 0.001);
  ASSERT_NEAR(2, m.at(1, 2), 0.001);
  ASSERT_NEAR(2, m.at(1, 3), 0.001);
  ASSERT_NEAR(3, m.at(2, 1), 0.001);
  ASSERT_NEAR(6, m.at(2, 2), 0.001);
  ASSERT_NEAR(4, m.at(2, 3), 0.001);
}

TEST_F(MatrixTest, RowReduction1) {
  Matrix m(a, rowa, cola);
  m.rowReduction();
  ASSERT_NEAR(1, m.at(1, 1), 0.001);
  ASSERT_NEAR(2, m.at(1, 2), 0.001);
  ASSERT_NEAR(3, m.at(1, 3), 0.001);
  ASSERT_NEAR(0, m.at(2, 1), 0.001);
  ASSERT_NEAR(1, m.at(2, 2), 0.001);
  ASSERT_NEAR(1.5, m.at(2, 3), 0.001);
}

TEST_F(MatrixTest, RowReduction2) {
  Matrix m(c, rowc, colc);
  m.rowReduction();
  ASSERT_NEAR(1, m.at(1, 1), 0.001);
  ASSERT_NEAR(1, m.at(1, 2), 0.001);
  ASSERT_NEAR(1.5, m.at(1, 3), 0.001);
  ASSERT_NEAR(0, m.at(2, 1), 0.001);
  ASSERT_NEAR(0, m.at(2, 2), 0.001);
  ASSERT_NEAR(0, m.at(2, 3), 0.001);
}

TEST_F(MatrixTest, RowReduction3) {
  Matrix m(b, rowb, colb);
  m.rowReduction();
  ASSERT_NEAR(1, m.at(1, 1), 0.001);
  ASSERT_NEAR(2, m.at(1, 2), 0.001);
  ASSERT_NEAR(2, m.at(1, 3), 0.001);
  ASSERT_NEAR(0, m.at(2, 1), 0.001);
  ASSERT_NEAR(0, m.at(2, 2), 0.001);
  ASSERT_NEAR(-2, m.at(2, 3), 0.001);
}

TEST_F(MatrixTest, BackSubstitution1) {
  Matrix m(a, rowa, cola);
  m.rowReduction();
  m.backSubstitution();
  ASSERT_NEAR(1, m.at(1, 1), 0.001);
  ASSERT_NEAR(0, m.at(1, 2), 0.001);
  ASSERT_NEAR(0, m.at(1, 3), 0.001);
  ASSERT_NEAR(0, m.at(2, 1), 0.001);
  ASSERT_NEAR(1, m.at(2, 2), 0.001);
  ASSERT_NEAR(1.5, m.at(2, 3), 0.001);
}

TEST_F(MatrixTest, BackSubstitution) {
  Matrix m(c, rowc, colc);
  m.rowReduction();
  m.backSubstitution();
  ASSERT_NEAR(1, m.at(1, 1), 0.001);
  ASSERT_NEAR(1, m.at(1, 2), 0.001);
  ASSERT_NEAR(1.5, m.at(1, 3), 0.001);
  ASSERT_NEAR(0, m.at(2, 1), 0.001);
  ASSERT_NEAR(0, m.at(2, 2), 0.001);
  ASSERT_NEAR(0, m.at(2, 3), 0.001);
}

TEST_F(MatrixTest, GaussianElimination) {
  Matrix m(a, rowa, cola);
  MathVector ans;
  ans = m.gaussianElimination();
  ASSERT_NEAR(1, m.at(1, 1), 0.001);
  ASSERT_NEAR(0, m.at(1, 2), 0.001);
  ASSERT_NEAR(0, m.at(1, 3), 0.001);
  ASSERT_NEAR(0, m.at(2, 1), 0.001);
  ASSERT_NEAR(1, m.at(2, 2), 0.001);
  ASSERT_NEAR(1.5, m.at(2, 3), 0.001);
  ASSERT_NEAR(0, ans[0], 0.001);
  ASSERT_NEAR(1.5, ans[1], 0.001);
}

TEST_F(MatrixTest, NoSolutionException1) {
  Matrix m(b, rowb, colb);
  ASSERT_ANY_THROW(m.gaussianElimination());
  ASSERT_NEAR(1, m.at(1, 1), 0.001);
  ASSERT_NEAR(2, m.at(1, 2), 0.001);
  ASSERT_NEAR(2, m.at(1, 3), 0.001);
  ASSERT_NEAR(0, m.at(2, 1), 0.001);
  ASSERT_NEAR(0, m.at(2, 2), 0.001);
  ASSERT_NEAR(-2, m.at(2, 3), 0.001);
}

TEST_F(MatrixTest, InfiniteException2) {
  Matrix m(d, rowd, cold);
  ASSERT_ANY_THROW(m.gaussianElimination());
  ASSERT_NEAR(1, m.at(1, 1), 0.001);
  ASSERT_NEAR(2, m.at(1, 2), 0.001);
  ASSERT_NEAR(3, m.at(1, 3), 0.001);
  ASSERT_NEAR(0, m.at(2, 1), 0.001);
  ASSERT_NEAR(0, m.at(2, 2), 0.001);
  ASSERT_NEAR(0, m.at(2, 3), 0.001);
}


#endif
