#ifndef POLYGON_H
#define POLYGON_H
#include "./vector.h"

class Polygon{
public:
  Polygon(){
      _side = -1;
      _ver = nullptr;
  }
  
  Polygon(Vector a[], int s){
      _side = s;
      Vector c = centroid(a, _side);
      Vector g = a[0] - c;
      AngleComparator comp(g, c);
      std::sort(a+0, a+_side, comp);
      _ver = new Vector [_side];
      for (int i=0; i<_side; i++){
          _ver[i] = a[i];
      }
  }
  
  ~Polygon(){
      if (_ver != nullptr){
          delete [] _ver;
      }
  }
  
  Vector point(int i){
      if (i > _side){
          throw "Out of Range";
      }
      return _ver[i-1];
  }
  
  int sides(){
      return _side;
  }
  
  double perimeter(){
      double sum = 0;
      for (int i=1; i<_side; i++){
          sum += (_ver[i] - _ver[i-1]).length();
      }
      sum += (_ver[0] - _ver[_side - 1]).length();
      return sum;
  }

  double area(){
      double result = 0;
      for (int i=1; i<_side-1; i++){
          result += _ver[0].areaWith(_ver[i], _ver[i+1]);
      }
      return result;
  }

private:
  int _side;
  Vector * _ver;
};

template <class RandomAccessIterator, class Condition>
std::vector<Polygon *> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition cond){
    std::vector<Polygon *> result;
    int n = end - begin;
    for (int i=0; i<n; i++){
        if (cond(*(begin+i))){
            result.push_back(*(begin+i));
        }
    }
    return result;
}



#endif
