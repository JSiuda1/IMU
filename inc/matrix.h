#ifndef MATRIX__H
#define MATRIX__H

#include "vector.h"

template <int SIZE>
class Matrix{
  Vector<SIZE>* matrix;

  public:
  Matrix();
  Matrix(std::initializer_list<Vector<SIZE>> arg);
  Matrix(const Matrix<SIZE>& _arg);
  
  void test();

  ~Matrix() { delete[] matrix; };
};


template <int SIZE>
Matrix<SIZE>::Matrix(){
  matrix = new Vector<SIZE>[SIZE];
}

template <int SIZE>
Matrix<SIZE>::Matrix(std::initializer_list<Vector<SIZE>> arg) {
  matrix = new Vector<SIZE>[SIZE];
  
  for (int i = 0; i < SIZE; ++i) {
   matrix[i] = *(arg.begin() + i);
  }
}

template <int SIZE>
Matrix<SIZE>::Matrix(const Matrix<SIZE>& _arg) {
  matrix = new Vector<SIZE>[SIZE];

  for (int i = 0; i < SIZE; ++i) {
    matrix[i] = _arg.matrix[i];
  }
}

template <int SIZE>
void Matrix<SIZE>::test(){
  for(int i=0; i < SIZE; ++i){
    std::cout << matrix[i] << std::endl;
  }
}

template class Matrix<3>;

#endif