# OOP HW5
For this assignment, please put class MathVector in src/math_vector.h, class Matrix in src/matrix.h. Test class Vector in test/ut_vector.h, test class Matrix in test/ut_matrix.h.
## Purpose of this assignment

Let Matrix can calculate Gaussian Elimination and get solution.
  
## Problems



In this assignment, you are asked to implement several method in MathVector and Matrix to make Matrix able to calculate Gaussian Elimination.

Please implement these class and methods:

-   MathVector::MathVector()
-   MathVector::MathVector(int dim)
-   MathVector::MathVector(double a[], int dim)
-   MathVector::MathVector(MathVector const & u)
-   MathVector & MathVector::operator = (MathVector const & v)
-   MathVector::~MathVector()
-   double & MathVector::operator [] (int index) //start with 0
-   int MathVector::dimension() const
-   MathVector MathVector::operator + (MathVector & v)
-   MathVector MathVector::scale(double scale)
-   Matrix::Matrix(MathVector *a[], int row, int col)
-   Matrix::Matrix(Matrix const & a)
-   Matrix::~Matrix()
-   double Matrix::at(int row, int col) const //start with 1, 1
-   void Matrix::rowReduction()
-   void Matrix::backSubstitution()
-   MathVector Matrix::gaussianElimination()
## Limitation

-   Your Matrix should store data with *MathVector, you will get 0 point if you use *double
-   You should use test fixture class to manage your test data.
-   Please prevent any possable memory leak and dangling referance.
-   After row reduction, the pivot in each row should be 1
-   All Gaussian Elimination test datas in ta test are n by n+1 (col=row+1) matrix.
