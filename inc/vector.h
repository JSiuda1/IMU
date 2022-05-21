#ifndef VECTOR__H
#define VECTOR__H

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

class Vector{
  double *vec;
  size_t size;

  public:
  Vector() {vec = NULL; size = 0;}; //dump constructor, use only when you know what are you doing
  Vector(const size_t & _size);
  Vector(std::initializer_list<double> arg);
  Vector(const size_t & size, const double & val);
  Vector(const Vector & _vec);
  Vector& operator=(const Vector & arg);
  Vector operator+(const Vector & arg) const;
  Vector operator-(const Vector & arg) const;
  const double & operator[](int index) const;
  double & operator[](int index);
  size_t getSize() const;
  double crossProduct() const;
  double crossProduct(const Vector & arg) const;
  double length() const;
  void normalize();
    
  ~Vector();
};

std::ostream & operator<<(std::ostream & strm, const Vector & arg);

Vector::Vector(const size_t & _size){
  size = _size;
  vec = new double[_size];
  memset(vec, 0, size);
}

Vector::Vector(std::initializer_list<double> arg){
  size = arg.size();
  vec = new double[size];
  memcpy(vec, arg.begin(), sizeof(double)*size);
}

Vector::Vector(const size_t & _size, const double & val){
  size = _size;
  vec = new double[size];

  for(int i=0; i < size; ++i){
    vec[i] = val;
  }
}

Vector::Vector(const Vector & _vec){
  size = _vec.size;
  vec = new double[size];
  
  memcpy(vec, _vec.vec, sizeof(double)*size);
}

Vector& Vector::operator=(const Vector & arg){
  if(size == arg.size){
    memcpy(vec, arg.vec, sizeof(double)*size);

  }else if(size == 0){ //dump constructor case 
    size = arg.size;
    vec = (double*)malloc(sizeof(double)*size);
    memcpy(vec, arg.vec, sizeof(double)*size);
    
  }else{  //fit to size of arg;
    /*
    size = arg.size;
    vec = (double*)realloc(vec, sizeof(double)*size);
    memcpy(vec, arg.vec, sizeof(double)*size);
    */
  }

  return *this;
}


Vector Vector::operator+(const Vector & arg) const{
  Vector result(size);

  if(size == arg.size){
    for(int i=0; i < size; ++i){
      result.vec[i] = vec[i] + arg.vec[i];
    }
  }
  
  return result;
}

Vector Vector::operator-(const Vector & arg) const{
  Vector result(size);

  if(size == arg.size){
    for(int i=0; i < size; ++i){
      result.vec[i] = vec[i] - arg.vec[i];
    }
  }

  return result;
}


const double & Vector::operator[](int index) const{
  if(index < 0 || index >= size){
    return vec[0];
  }
  
  return vec[index];
}


double & Vector::operator[](int index){
  if(index < 0 || index >= size){
    return vec[0]; //to not throwing exception
  }
  
  return vec[index];
}

size_t Vector::getSize() const{
  return size;
}

double Vector::crossProduct() const{
  double result = 0;
  
  for(int i=0; i < size; ++i){
    result += vec[i] * vec[i];
  }
    
  return result;
}

double Vector::crossProduct(const Vector & arg) const{
  double result = 0;
  if(size == arg.size){
    for(int i=0; i < size; ++i){
      result += vec[i] * arg[i];
    }
  } 
    
  return result;
}

double Vector::length() const{
  return sqrt(this->crossProduct(*this));
}

void Vector::normalize(){
  double norm = length();
  
  if(norm == 0){
    return; //zero vector case 
  }
  
  for(int i=0; i < size; ++i){
    vec[i] = vec[i]/norm;
  }
}

Vector::~Vector(){
  delete[] vec;
}

std::ostream & operator<<(std::ostream & strm, const Vector & arg){
    size_t size = arg.getSize();
    strm<<"[";

    for(int i=0; i<size-1; ++i){
      strm<<arg[i]<<", ";
    }
    strm<<arg[size-1]<<"]";

    return strm;
}

#endif