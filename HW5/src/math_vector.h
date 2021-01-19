#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

class MathVector {
public:
  MathVector(){
    _vec = nullptr;
    _dim = 0;
  }

  MathVector(double a[], int dim){
    initialize(a, dim);
  }

  MathVector(int dim){
    double a[dim] = {0};  
    initialize(a, dim);
  }

  MathVector(MathVector const & u){
    initialize(u._vec, u._dim);
  }

  MathVector & operator = (MathVector const & v) {
    if (_vec != 0){
      delete [] _vec;
    }
    initialize(v._vec, v._dim);
    return *this;  //return the rvalue of the pointer to the mathvector
  }

  ~MathVector(){
    if (_vec != nullptr){
      delete [] _vec;
    }
  }

  double & operator [] (int index){  //start with 0
    if (index >= _dim){
      throw "Out of scope";
    }
    return _vec[index];
  }

  int dimension() const {
    return _dim;
  }

  MathVector operator + (MathVector & v) {
    if (_dim != v._dim){
      throw "dimension different";
    }
    MathVector result(_dim);
    for (int i = 0; i < v.dimension(); i++){
      result[i] = _vec[i] + v[i]; 
    }
    return result;
  }

  MathVector scale(double scale){
    MathVector result(_dim);
    for (int i = 0; i < _dim; i++){
      result[i] = scale * _vec[i];
    }
    return result;
  }

private:
  void initialize(double * a, int dim){
    _dim = dim;
    _vec = new double[_dim];
    for(int i=0 ; i<_dim ; i++){
      _vec[i] = a[i];
    }
  }
  double * _vec;
  int _dim;
};


#endif
