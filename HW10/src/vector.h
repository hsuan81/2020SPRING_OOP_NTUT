#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>
#include <sstream>
#include <vector>

class Vector {
public:
    Vector(double a[], int dim) {
        initialize(a, dim);
    }

    Vector() {
        _dim = -1;
        _vec = nullptr;
    }

    Vector(Vector const & u) {
        initialize(u._vec, u._dim);
    }

    Vector(int dim){
        double * a = new double [dim];
        for (int i=0; i< dim; i++){
            a[i] = 0;
        }
        initialize(a, dim); 
    }

    ~Vector() {
        if (_vec != nullptr)
            delete [] _vec;
    }

    int dim() const{
        return _dim;
    }

    double at(int i) const{
        if (i >= _dim) {
        throw "Out of scope";
        }
        return _vec[i];
    }

    Vector &operator = (Vector const & u) {
        if (_vec != nullptr){
            delete [] _vec;
        }
        initialize(u._vec, u._dim);
        return *this;
    }

    Vector operator + (Vector const & u) const{
        Vector result = *this;
        if (result._dim != u._dim){
            throw "Different dimension.";
        }
        for (int i=0; i<result._dim; i++){
            result._vec[i] += u._vec[i];
        }
        return result;
    }

    Vector operator - (Vector const & u) const{
        Vector result = *this;
        if (result._dim != u._dim){
            throw "Different dimension.";
        }
        for (int i=0; i<result._dim; i++){
            result._vec[i] -= u._vec[i];
        }
        return result;
    }

    double length() const{
        double sum = 0;
        for (int i=0; i<_dim; i++){
            sum += _vec[i] * _vec[i];
        }
        return sqrt(sum);
    }

    double angle(Vector u) const{
        if (_dim != u._dim){
            throw "Different dimension";
        }
        double dot = 0;
        for (int i=0; i<_dim; i++){
            dot += _vec[i] * u._vec[i];
        }
        double result = dot/(length() * u.length());
        if (PointDirection(u)){
            return acos(result);
        }
        return 2*M_PI - acos(result);
    }
    
    bool PointDirection(Vector const & u) const{
        return at(0) * u.at(1) - at(1) * u.at(0) >= 0;
    }

    Vector scale(double n){
        Vector result = *this;
        for (int i=0; i<_dim; i++){
            result._vec[i] = result._vec[i] * n;
        }
        return result;
    }

    double area(Vector const & u, Vector const & v = Vector(2)) const{
        double result = 0;
        double a = (u-*this).length();
        double b = (v-*this).length();
        double c = (u-v).length();
        double s = (a + b + c)/2;
        result = s * (s-a) * (s-b) * (s-c);
        return sqrt(result);
    }

    std::string toString() const {
        std::stringstream ss;
        std::string result;
        ss << "(";
        for (int i=0; i<_dim; i++){
            ss << (*this).at(i);
            if (i != (_dim - 1)){
                ss << ",";
            }
        }
        ss << ")";
        return ss.str();
    }


private:
    void initialize(double * a, int dim){
        _dim = dim;
        _vec = new double[_dim];
        for(int i=0 ; i<_dim ; i++){
            _vec[i] = a[i];
        }
    }

    int _dim;
    double * _vec;
};

Vector centroid(std::vector<Vector> a, int numVertices){
    Vector result(a[0]);
    for (int i=1; i<numVertices; i++){
        result = result + a[i];
    }
    return result.scale(1.0/numVertices);
    }

class AngleComparator{
public:
  AngleComparator(Vector const & basis, Vector const & point){
      _g = basis;
      _c = point;
  }

  bool operator () (Vector & u, Vector & v){
      return _g.angle(u-_c) < _g.angle(v-_c);
  }

private:
  Vector _g;
  Vector _c;
};
#endif