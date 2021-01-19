#include "../src/vector.h"
#include <math.h>

class VectorTest : public ::testing::Test {
protected:
  void SetUp() override {
    a[0] = 1;
    a[1] = 0;
    a[2] = 1;

    b[0] = 1;
    b[1] = 2;
    b[2] = 3;

    c[0] = 1;
    c[1] = 1;

    d[0] = 1;
    d[1] = 0;

    e[0] = 0;
    e[1] = 1;

    f[0] = -1;
    f[1] = -1;
  }
  double a[3];
  double b[3];
  double c[2];
  double d[2];
  double e[2];
  double f[2];
};

TEST_F(VectorTest, Constructor) {
    Vector v(a, 3);
    ASSERT_EQ(3, v.dim());
    ASSERT_NEAR(1, v.at(1), 0.1);
    ASSERT_NEAR(0, v.at(2), 0.1);
    ASSERT_NEAR(1, v.at(3), 0.1);
}

TEST_F(VectorTest, DefaultConstructor) {
    Vector v;
    ASSERT_EQ(-1, v.dim());
}

TEST_F(VectorTest, CopyConstructor) {
    Vector v(a, 3);
    Vector s(v);
    ASSERT_EQ(3, v.dim());
    ASSERT_NEAR(1, s.at(1), 0.1);
    ASSERT_NEAR(0, s.at(2), 0.1);
    ASSERT_NEAR(1, s.at(3), 0.1);
}

TEST_F(VectorTest, getDim) {
    Vector v(a, 3);
    ASSERT_EQ(3, v.dim());
}

TEST_F(VectorTest, getPoint) {
    Vector v(a, 3);
    ASSERT_NEAR(1, v.at(1), 0.1);
    ASSERT_NEAR(0, v.at(2), 0.1);
    ASSERT_NEAR(1, v.at(3), 0.1);
}

TEST_F(VectorTest, PointOutOfScope) {
    Vector v(a, 3);
    ASSERT_ANY_THROW(v.at(4));
}

TEST_F(VectorTest, Addition) {
    Vector v(a, 3);
    Vector u(b, 3);
    Vector t;
    t = v + u;
    ASSERT_NEAR(2, t.at(1), 0.1);
    ASSERT_NEAR(2, t.at(2), 0.1);
    ASSERT_NEAR(4, t.at(3), 0.1);
    ASSERT_EQ(3, t.dim());
}

TEST_F(VectorTest, AdditionByDifferentDim) {
    Vector v(a, 3);
    Vector u(c, 2);
    // Vector t;
    ASSERT_ANY_THROW(v + u);
}

TEST_F(VectorTest, Substraction) {
    Vector v(a, 3);
    Vector u(b, 3);
    Vector t;
    t = u - v;
    ASSERT_NEAR(0, t.at(1), 0.1);
    ASSERT_NEAR(2, t.at(2), 0.1);
    ASSERT_NEAR(2, t.at(3), 0.1);
    ASSERT_EQ(3, t.dim());
}

TEST_F(VectorTest, SubstractionByDifferentDim) {
    Vector v(a, 3);
    Vector u(c, 2);
    ASSERT_ANY_THROW(v - u);
}

TEST_F(VectorTest, getLength) {
    Vector v(a, 3);
    ASSERT_NEAR(1.41, v.length(), 0.01);
}

TEST_F(VectorTest, Angle) {
    Vector v(d, 2);
    Vector u(c, 2);
    //ASSERT_NEAR(45, v.angle(u), 0.1);
    ASSERT_NEAR(M_PI/4, v.angle(u), 0.1);
}

TEST_F(VectorTest, Angle90) {
    Vector v(d, 2);
    Vector u(e, 2);
    ASSERT_NEAR(M_PI/2, v.angle(u), 0.01);
}

TEST_F(VectorTest, AngleGreaterThan180) {
    Vector v(d, 2);
    Vector s(f, 2);
    ASSERT_NEAR(5*M_PI/4, v.angle(s), 0.1);
}

TEST_F(VectorTest, AngleWrongDim) {
    Vector v(a, 3);
    Vector u(e, 2);
    ASSERT_ANY_THROW(v.angle(u));
}

TEST_F(VectorTest, Centroid){
    Vector v(d, 2);
    Vector u(e, 2);
    Vector s(f, 2);
    Vector m[3] = {v, u, s};
    Vector result = centroid(m, 3);
    ASSERT_NEAR(0, result.at(1), 0.1);
    ASSERT_NEAR(0, result.at(2),0.1);
}

TEST_F(VectorTest, AreaWith){
    Vector v(d, 2);
    Vector u(e, 2);
    Vector s(f, 2);
    ASSERT_NEAR(1.5, v.areaWith(u, s), 0.1);
}

TEST_F(VectorTest, Scaling) {
    Vector v(a, 3);
    Vector result = v.scale(2);
    ASSERT_NEAR(2, result.at(1), 0.01);
    ASSERT_NEAR(0, result.at(2), 0.01);
    ASSERT_NEAR(2, result.at(3), 0.01);
}

TEST_F(VectorTest, AngleComparison){
    Vector v(d, 2);
    Vector u(e, 2);
    Vector s(f, 2);
    AngleComparator com((v-s), s);
    ASSERT_TRUE(com(v, u));
}
