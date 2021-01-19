#ifndef MATRIX_H
#define MATRIX_H
#include "math_vector.h"

class Matrix {
public:
  Matrix(MathVector a[], int row, int col){
    _row = row;
    _col = col;
    _m = new MathVector [_row];
    for (int i = 0; i < _row; i++){
      if (a[i].dimension() != _col){
        throw ("Mismatch dimension");
      }
      _m[i] = a[i];
    }
  }

  Matrix(Matrix const & a){  // copy constructor
    _row = a._row;
    _col = a._col;
    _m = new MathVector [_row];
    for(int i=0 ; i<_row ; i++){
      _m[i] = a._m[i];
    }
  }

  ~Matrix() { // destructor
    if(_m != nullptr){
      delete [] _m;
    }
  }

  double at(int row, int col) const {
    return _m[(row-1)][(col-1)];
  }
  
  void rowReduction(){
    for (int i = 0; i < _row-1; i++){
      for(int j = i+1; j < _row; j++){
        double f = _m[j][i]/_m[i][i];
        for (int k = 0; k < _col; k++){
          _m[j][k] = _m[j][k] - f*_m[i][k];
        }
      }
    }
    for (int i = 0; i <_row; i++){
      int k = i;
      if (k >= _col-1)
        k -= 1;
      double f = _m[i][k];
      if (f == 0){
        break;
      }
      for (int j = k; j < _col; j++){
        _m[i][j] = _m[i][j] / f;
      }
    }
  }
  

void backSubstitution(){
  for (int i = _row-1; i > 0; i--){
    if (i == _col-1 or _m[i][i] == 0)
      continue;
    for (int j = i-1; j >= 0; j-- ){
      double f = _m[j][i];
      for (int k = i; k < _col; k++){
        _m[j][k] = _m[j][k] - f*_m[i][k];
      }  
    }
  }
}

MathVector gaussianElimination(){
  MathVector answer(_col-1);
  this->rowReduction();
  if (_m[_col-2][_col-2] == 0){
    if (_m[_col-2][_col-1] == 0){
      throw ("infinite solution");
    }
    else{
      throw ("no solution");
    }
  }
  this->backSubstitution();
  for (int i = 0; i < _row; i++){
    answer[i] = _m[i][_col-1];
  }
  return answer;
} 


private:
  int _row;
  int _col;
  MathVector *_m;
};

#endif
