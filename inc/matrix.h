#ifndef MATRIX__H
#define MATRIX__H

#include "vector.h"
#include "exception"
#include <iostream>

class Matrix{
  Vector** matrix;
  size_t row;
  size_t collumn;

  public:
  Matrix() = delete;
  Matrix(const size_t & _row, const size_t & _collumn);
  Matrix(std::initializer_list<Vector> arg);
  Matrix(const Matrix& _arg);
  Matrix& operator=(const Matrix & arg);
  Matrix operator+(const Matrix & arg) const;
  Matrix operator-(const Matrix & arg) const;

  void test() const;

  ~Matrix();
};


Matrix::Matrix(const size_t& _row, const size_t& _collumn) {
  row = _row;
  collumn = _collumn;

  matrix = (Vector**)malloc(row * sizeof(Vector));
  for (int i = 0; i < row; ++i) {
    matrix[i] = (Vector*)calloc(1, sizeof(Vector));
    *matrix[i] = Vector(_collumn);
  }
}

void Matrix::test() const{
  for (int i = 0; i < row; ++i) {
    std::cout << *matrix[i] << std::endl;
  }
}

Matrix::~Matrix() {
  for (int i = 0; i < row; ++i) {
    free(matrix[i]);
  }
  free(matrix);
}

/*
Matrix::Matrix(const size_t & _row, const size_t & _collumn){
  //Vector temp(_collumn); 
  row = _row;
  collumn = _collumn;
  
  matrix = new Vector[row];
  for(int i=0; i < row; ++i){
    matrix[i] = Vector(collumn);
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

  matrix = (Vector*)malloc(sizeof(Vector) * row + sizeof(double)*collumn);
  for(int i=0; i < row; ++i){
    matrix[i] = Vector(*(arg.begin() + i));
  }
}

Matrix::Matrix(const Matrix & _arg) {
  matrix = (Vector*)malloc(sizeof(Vector) * row);
  
  for(int i=0; i < row; ++i){
    matrix[i] = _arg.matrix[i];
  }
}

Matrix& Matrix::operator=(const Matrix & arg){
  //go over this
  std::cout << "przypisanie - początek\n";
  if(row == arg.row && collumn == arg.collumn){
    for(int i=0; i < row; ++i){
      matrix[i] = arg.matrix[i];
    }
  }
  std::cout << "Przypisanie koenic\n";
  
  return *this;
}

Matrix Matrix::operator+(const Matrix & arg) const{
  Matrix result(row, collumn);
  std::cout << "Dodawanie - początek\n";
  if(row == arg.row && collumn == arg.collumn){
    for(int i=0; i < row; ++i){
      for(int j=0; j < collumn; ++j){
        result.matrix[i][j] = matrix[i][j] + arg.matrix[i][j];
      }
    }
  }else{// if matrixes havn't same size
    result = *this; 
  }
  std::cout << "Dodawanie - koniec\n";
  result.test();
  return result;
}

Matrix Matrix::operator-(const Matrix & arg) const{
  Matrix result(row, collumn);

  if(row == arg.row && collumn == arg.collumn){
    for(int i=0; i < row; ++i){
      for(int j=0; j < collumn; ++j){
        result.matrix[i][j] = matrix[i][j] - arg.matrix[i][j];
      }
    }
  }else{// if matrixes havn't same size
    result = *this;
  }

  return result;
}
  

void Matrix::test() const{
  for(int i=0; i < row; ++i){
    std::cout << matrix[i] << std::endl;
  }
  std::cout << std::endl;
}


Matrix::~Matrix(){
  for(int i=0; i < row; ++i){
    matrix[i].~Vector(); //free vectors
  }
  free(matrix); //free matrix
}
*/

#endif