# OOP HW7
For this assignment, please put class Polygon in src/polygon.h and class Vector in src/vector.h. Test class Polygon in test/ut_polygon.h, test class Vector in test/ut_vector.h.

## Purpose of this assignment

Let student parctice template method and lambda.
  
## Problems

In this assignment, you are asked to implement a finding method with perimeter and area of polygons. The only standard container you can use is setting up the std::vector of the polygons before using findAll method.

Please implement these class and methods:

-   Vector::int dim()const
-   Vector::double at(int i)const
-   Vector::Vector operator+
-   Vector::Vector operator-
-   Vector::double length()const
-   Vector::double angle(Vector u)const
-   Polygon::Vector point(int i)
-   Polygon::int sides()
-   Polygon::double perimeter()
-   Polygon::double area()
-   std::vector<Polygon *> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition cond)
-   implement constructor, destructor or operator= as needed by your self.

### [](#findall)findAll:

findAll is a template method which prototype is

```
template <class RandomAccessIterator, class Condition>
std::vector<Polygon *> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition cond);
```

when we have a list of polygons

std::vector<Polygon *> polygons = {...}

we can call findAll to find polygons that match the condiction

for example

```
std::vector<Polygon *> result = findAll(polygons.begin(), polygons.end(), [](Polygon *s) {
  return s->area() > 2 && s->area() < 5.5;
}); // find polygon that area larger then 2 and less then 5
```

or

```
std::vector<Polygon *> result = findAll(polygons.begin()+2, polygons.end(), [](Polygon *s) {
  return s->perimeter() > 7;
}); // find polygon that perimeter larger then 7 in polygons[2:] range
```
