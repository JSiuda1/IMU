#ifndef MATRIX__H
#define MATRIX__H

#include "vector.h"
#include "exception"
#include <iostream>

class Matrix{
  Vector* matrix;
  size_t row;
  size_t collumn;

  public:
  Matrix() = delete;
  Matrix(const size_t & _row, const size_t & _collumn);
  Matrix(std::initializer_list<Vector> arg);
  Matrix(const Matrix& _arg);
  Matrix operator=(const Matrix & arg);
  Matrix operator+(const Matrix & arg) const;
  Matrix operator-(const Matrix & arg) const;
  Matrix operator*(const Matrix & arg) const;
  Matrix operator*(const Vector & arg) const;
  const Vector & operator[](int index) const;
  Vector & operator[](int index);
  void transpose();
  //double determinant();

  void test() const;

  ~Matrix();
};


Matrix::Matrix(const size_t& _row, const size_t& _collumn) {
  row = _row;
  collumn = _collumn;

  matrix = new Vector[row];
  for (int i = 0; i < row; ++i) {
    matrix[i] = Vector(_collumn);
  }
}

Matrix::Matrix(std::initializer_list<Vector> arg) {
  row = arg.size();
  collumn = arg.begin()->getSize();
  
  for(int i = 0; i < row; ++i){
    if(collumn != (arg.begin() + i)->getSize()){
      throw std::invalid_argument("Matrix is not mxn");
    }
  }

  matrix = new Vector[row];
  for(int i=0; i < row; ++i){
    matrix[i] = Vector(*(arg.begin() + i));
  }
}

Matrix::Matrix(const Matrix & _arg) {
  row = _arg.row;
  collumn = _arg.collumn;
  matrix = new Vector[row];
  
  for(int i=0; i < row; ++i){
    matrix[i] = _arg.matrix[i];
  }
}


Matrix Matrix::operator=(const Matrix & arg){
  //go over this
  if(row == arg.row && collumn == arg.collumn){
    for(int i=0; i < row; ++i){
      matrix[i] = arg.matrix[i];
    }
  }
  
  return *this;
}

Matrix Matrix::operator+(const Matrix & arg) const{
  Matrix result(row, collumn);

  if(row == arg.row && collumn == arg.collumn){
    for(int i=0; i < row; ++i){
      result.matrix[i] = matrix[i] + arg.matrix[i];
    }
  }else{// if matrixes havn't same size
    result = *this; 
  }

  return result;
}

Matrix Matrix::operator-(const Matrix & arg) const{
  Matrix result(row, collumn);

  if(row == arg.row && collumn == arg.collumn){
    for(int i=0; i < row; ++i){
      for(int j=0; j < collumn; ++j){
        result.matrix[i] = matrix[i] - arg.matrix[i];
      }
    }
  }else{// if matrixes havn't same size
    result = *this;
  }

  return result;
}

Matrix Matrix::operator*(const Matrix & arg) const{
  Matrix result(row, arg.collumn);
  
  if(collumn == arg.row){ 
    for(int i=0; i < row; ++i){ 
      for(int j=0; j < arg.collumn; ++j){ 
        for(int k=0; k < collumn; ++k){
          result.matrix[i][j]+=matrix[i][k]*arg.matrix[k][j];
        }
      }
    }
  }else{
    result = *this;
  }
  return result;
}

Matrix Matrix::operator*(const Vector & arg) const{
  Matrix result(row, 1);

  if(collumn == arg.getSize()){
    for(int i=0; i < row; ++i){ 
      for(int k=0; k < collumn; ++k){
        result.matrix[i][k]+=matrix[i][k]*arg[k];
      }
    }
  }else{
    result = *this;
  }

  return result;
}

const Vector & Matrix::operator[](int index) const{
  if(index < 0 || index >= row){
    return matrix[0];
  }
  
  return matrix[index];
}


Vector & Matrix::operator[](int index){
  if(index < 0 || index >= row){
    return matrix[0];
  }
  
  return matrix[index];
}

void Matrix::transpose(){
  Matrix result(collumn, row);
  for(int i=0; i < collumn; ++i){
    for(int j=0; j < row; ++j){
      result.matrix[i][j] = matrix[j][i];
    }
  }
  delete[] matrix;
  row = result.row;
  collumn = result.collumn;
  
  matrix = new Vector[row];
  
  for(int i=0; i < row; ++i){
    matrix[i] = result.matrix[i];
  }
}
  
void Matrix::test() const{
  for (int i = 0; i < row; ++i) {
    std::cout << matrix[i] << std::endl;
  }
  std::cout << "\n";
}


Matrix::~Matrix() {
  delete[] matrix;
}

#endif