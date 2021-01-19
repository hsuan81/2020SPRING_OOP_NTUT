#ifndef UT_VECTOR_H
#define UT_VECTOR_H
#include "../src/math_vector.h"

class VectorTest : public ::testing::Test {
protected:
  void SetUp() override {
    a[0] = 1;
    a[1] = 1;
    a[2] = 1;

    b[0] = 1;
    b[1] = 2;
    b[2] = 3;

    c[0] = 1;
    c[1] = 2;
  }
  double a[3];
  double b[3];
  double c[2];
};

TEST(MathVector, Constructor) {
  MathVector m;
  ASSERT_EQ(0, m.dimension());
}

TEST(MathVector, DefaultConstructor) {
  MathVector m(3);
  ASSERT_EQ(3, m.dimension());
  ASSERT_NEAR(0, m[0], 0.001);
  ASSERT_NEAR(0, m[1], 0.001);
  ASSERT_NEAR(0, m[2], 0.001);
}

TEST_F(VectorTest, ArgumentConstructor) {
  MathVector m(a, 3);
  ASSERT_NEAR(1, m[0], 0.001);
  ASSERT_NEAR(1, m[1], 0.001);
  ASSERT_NEAR(1, m[2], 0.001);
}

TEST_F(VectorTest, CopyConstructor) {
  MathVector m(a, 3);
  MathVector v(m);
  ASSERT_NEAR(1, v[0], 0.001);
  ASSERT_NEAR(1, v[1], 0.001);
  ASSERT_NEAR(1, v[2], 0.001);
}

TEST_F(VectorTest, Addition){
  MathVector u(a, 3);
  MathVector v(b, 3);
  MathVector result;
  result = u + v;
  ASSERT_EQ(3, result.dimension());
  ASSERT_NEAR(2, result[0], 0.001);
  ASSERT_NEAR(3, result[1], 0.001);
  ASSERT_NEAR(4, result[2], 0.001);
}

TEST_F(VectorTest, AdditionError){
  MathVector u(a, 3);
  MathVector v(c, 2);
  ASSERT_ANY_THROW(u + v);
}

TEST_F(VectorTest, CopyAssignment){
  MathVector u(a, 3);
  MathVector v;
  v = u;
  ASSERT_NEAR(1, v[0], 0.001);
  ASSERT_NEAR(1, v[1], 0.001);
  ASSERT_NEAR(1, v[2], 0.001);
}

TEST_F(VectorTest, Component){
  MathVector u(c, 2);
  ASSERT_NEAR(1, u[0], 0.001);
  ASSERT_NEAR(2, u[1], 0.001);
}

TEST_F(VectorTest, ComponentError){
  MathVector u(c, 2);
  ASSERT_ANY_THROW(u[3]);
}

TEST_F(VectorTest, GetDimension){
  MathVector u(a, 3);
  ASSERT_EQ(3, u.dimension());
}

TEST_F(VectorTest, Scaling){
  MathVector u(a, 3);
  MathVector result;
  result = u.scale(3);
  ASSERT_NEAR(3, result[0], 0.001);
  ASSERT_NEAR(3, result[1], 0.001);
  ASSERT_NEAR(3, result[2], 0.001);
}

#endif