#include "../src/polygon.h"
#include "../src/vector.h"
#include <math.h>

class PolygonTest : public ::testing::Test {
protected:
  void SetUp() override {
    a[0] = 1;
    a[1] = 0;
    

    b[0] = 3;
    b[1] = 0;
    

    c[0] = 1;
    c[1] = 1;
    

    d[0] = 3;
    d[1] = 1;
    
  }
  double a[2];
  double b[2];
  double c[2];
  double d[2];

  
};

TEST_F(PolygonTest, DefaultConstructor){
    Polygon p;
    ASSERT_EQ(-1, p.sides());
}

TEST_F(PolygonTest, Constructor){
    Vector u(a, 2);
    Vector v(b, 2);
    Vector s(c, 2);
    Vector t(d, 2);
    Vector m[4] = {u, v, s, t};
    Polygon p(m, 4);
    ASSERT_EQ(2, p.point(1).dim());
    ASSERT_NEAR(1, p.point(1).at(1),0.1);
    ASSERT_NEAR(0, p.point(1).at(2),0.1);
    ASSERT_NEAR(3, p.point(2).at(1),0.1);
    ASSERT_NEAR(0, p.point(2).at(2),0.1);
    ASSERT_NEAR(3, p.point(3).at(1),0.1);
    ASSERT_NEAR(1, p.point(3).at(2),0.1);
    ASSERT_NEAR(1, p.point(4).at(1),0.1);
    ASSERT_NEAR(1, p.point(4).at(2),0.1);
}

TEST_F(PolygonTest, getPoint){
    Vector u(a, 2);
    Vector v(b, 2);
    Vector s(c, 2);
    Vector t(d, 2);
    Vector m[4] = {u, v, s, t};
    Polygon p(m, 4);
    ASSERT_EQ(2, p.point(1).dim());
    ASSERT_NEAR(1, p.point(1).at(1),0.1);
    ASSERT_NEAR(0, p.point(1).at(2),0.1);
    ASSERT_NEAR(3, p.point(2).at(1),0.1);
    ASSERT_NEAR(0, p.point(2).at(2),0.1);
    ASSERT_NEAR(3, p.point(3).at(1),0.1);
    ASSERT_NEAR(1, p.point(3).at(2),0.1);
    ASSERT_NEAR(1, p.point(4).at(1),0.1);
    ASSERT_NEAR(1, p.point(4).at(2),0.1);
}


TEST_F(PolygonTest, PointOutOfRange){
    Vector u(a, 2);
    Vector v(b, 2);
    Vector s(c, 2);
    Vector t(d, 2);
    Vector m[4] = {u, v, s, t};
    Polygon p(m, 4);
    ASSERT_ANY_THROW(p.point(5));
}

TEST_F(PolygonTest, getSides){
    Vector u(a, 2);
    Vector v(b, 2);
    Vector s(c, 2);
    Vector t(d, 2);
    Vector m[4] = {u, v, s, t};
    Polygon p(m, 4);
    ASSERT_EQ(4, p.sides());
}

TEST_F(PolygonTest, perimeter){
    Vector u(a, 2);
    Vector v(b, 2);
    Vector s(c, 2);
    Vector t(d, 2);
    Vector m[4] = {u, v, s, t};
    Polygon p(m, 4);  
    ASSERT_NEAR(6, p.perimeter(), 0.1);
    //std::cout<<p.perimeter()<<std::endl;
}

TEST_F(PolygonTest, perimeter2){
    Vector u(a, 2);
    Vector v(b, 2);
    double i[2] = {4, 1};
    double j[2] = {3, 2};
    double k[2] = {1, 2};
    double l[2] = {0, 1};
    Vector w(i, 2);
    Vector x(j, 2);
    Vector y(k, 2);
    Vector z(l, 2);
    Vector m[6] = {v, u, x, y, w, z};
    Polygon p(m, 6);  
    
    EXPECT_NEAR(3, p.point(1).at(1),0.1);
    EXPECT_NEAR(0, p.point(1).at(2),0.1);
    EXPECT_NEAR(4, p.point(2).at(1),0.1);
    EXPECT_NEAR(1, p.point(2).at(2),0.1);
    EXPECT_NEAR(3, p.point(3).at(1),0.1);
    EXPECT_NEAR(2, p.point(3).at(2),0.1);
    EXPECT_NEAR(1, p.point(4).at(1),0.1);
    EXPECT_NEAR(2, p.point(4).at(2),0.1);
    EXPECT_NEAR(1, p.point(6).at(1),0.1);
    EXPECT_NEAR(0, p.point(6).at(2),0.1);
    ASSERT_NEAR(4+4*sqrt(2), p.perimeter(), 0.01);
}

TEST_F(PolygonTest, area){
    Vector u(a, 2);
    Vector v(b, 2);
    Vector s(c, 2);
    Vector t(d, 2);
    Vector m[4] = {u, v, s, t};
    Polygon p(m, 4);
    ASSERT_NEAR(2, p.area(), 0.1);
}

TEST_F(PolygonTest, PerimeterLessThan7){
    double i[2] = {1, 2};
    double j[2] = {3, 2};
    Vector u(a, 2);
    Vector v(b, 2);
    Vector s(c, 2);
    Vector t(d, 2);
    Vector x(i, 2);
    Vector y(j, 2);
    Vector m[4] = {u, v, s, t};
    Vector n[4] = {u, v, x, y};
    Polygon p(m, 4);
    Polygon g(n, 4);
    std::vector<Polygon *> polygons {&p, &g};
    std::vector<Polygon *> result = findAll(polygons.begin(), polygons.end(), [](Polygon *z) {return z->perimeter() < 7;});
    ASSERT_EQ(1, result.size());
    ASSERT_NEAR(6, result[0]->perimeter(), 0.1);
    ASSERT_NEAR(1, result[0]->point(1).at(1),0.1);
    ASSERT_NEAR(0, result[0]->point(1).at(2),0.1);
    ASSERT_NEAR(3, result[0]->point(2).at(1),0.1);
    ASSERT_NEAR(0, result[0]->point(2).at(2),0.1);
    ASSERT_NEAR(3, result[0]->point(3).at(1),0.1);
    ASSERT_NEAR(1, result[0]->point(3).at(2),0.1);
    ASSERT_NEAR(1, result[0]->point(4).at(1),0.1);
    ASSERT_NEAR(1, result[0]->point(4).at(2),0.1);
}

TEST_F(PolygonTest, AreaLargerThan2){
    double i[2] = {1, 2};
    double j[2] = {3, 2};
    Vector u(a, 2);
    Vector v(b, 2);
    Vector s(c, 2);
    Vector t(d, 2);
    Vector x(i, 2);
    Vector y(j, 2);
    Vector m[4] = {u, v, s, t};
    Vector n[4] = {u, v, x, y};
    Polygon p(m, 4);
    Polygon g(n, 4);
    std::vector<Polygon *> polygons {&p, &g};
    std::vector<Polygon *> result = findAll(polygons.begin(), polygons.end(), [](Polygon *z) -> bool{return z->area() > 2 && z->area() < 5.5;});
    ASSERT_EQ(1, result.size());
    ASSERT_NEAR(4, result[0]->area(), 0.1);
    ASSERT_NEAR(1, result[0]->point(1).at(1),0.1);
    ASSERT_NEAR(0, result[0]->point(1).at(2),0.1);
    ASSERT_NEAR(3, result[0]->point(2).at(1),0.1);
    ASSERT_NEAR(0, result[0]->point(2).at(2),0.1);
    ASSERT_NEAR(3, result[0]->point(3).at(1),0.1);
    ASSERT_NEAR(2, result[0]->point(3).at(2),0.1);
    ASSERT_NEAR(1, result[0]->point(4).at(1),0.1);
    ASSERT_NEAR(2, result[0]->point(4).at(2),0.1);
}