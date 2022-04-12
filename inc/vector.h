#ifndef VECTOR__H
#define VECTOR__H

#include <iostream>
#include <vector>
#include <cmath>

template<int SIZE>
class Vector{
    double *vec;

    public:
    Vector();
    Vector(std::initializer_list<double> arg);
    Vector(const Vector<SIZE> & _vec);
    Vector<SIZE>& operator=(const Vector<SIZE> & arg);
    Vector<SIZE> operator+(const Vector<SIZE> & arg) const;
    Vector<SIZE> operator-(const Vector<SIZE> & arg) const;
    const double & operator[](int index) const;
    double & operator[](int index);
    double crossProduct(const Vector<SIZE> & arg) const;
    double length() const;
    void normalize();
    
    ~Vector() {free(vec);};
};

template<int SIZE>
std::ostream & operator<<(std::ostream & strm, const Vector<SIZE> & arg);


template <int SIZE>
Vector<SIZE>::Vector(){
  vec = (double*)calloc(SIZE, sizeof(double));
}

template <int SIZE>
Vector<SIZE>::Vector(std::initializer_list<double> arg){
  vec = (double*)calloc(SIZE, sizeof(double));

  memcpy(vec, arg.begin(), sizeof(double)*SIZE);
}

template <int SIZE>
Vector<SIZE>::Vector(const Vector<SIZE> & _vec){
  vec = (double*)calloc(SIZE, sizeof(double));
  
  memcpy(vec, _vec.vec, sizeof(double)*SIZE);
}

template <int SIZE>
Vector<SIZE>& Vector<SIZE>::operator=(const Vector<SIZE> & arg){
  Vector<SIZE> result;

  memcpy(vec, arg.vec, sizeof(double)*SIZE);

  return *this;
}

template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator+(const Vector<SIZE> & arg) const{
  Vector<SIZE> result;

  for(int i=0; i<SIZE; ++i){
    result.vec[i] = vec[i] + arg.vec[i];
  }

  return result;
}

template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator-(const Vector<SIZE> & arg) const{
  Vector<SIZE> result;

  for(int i=0; i<SIZE; ++i){
    result.vec[i] = vec[i] - arg.vec[i];
  }

  return result;
}

template <int SIZE>
const double & Vector<SIZE>::operator[](int index) const{
  if(index < 0 || index >= SIZE){
    return vec[0];
  }
  
  return vec[index];
}

template <int SIZE>
double & Vector<SIZE>::operator[](int index){
  if(index < 0 || index >= SIZE){
    return vec[0]; //to not throwing exception
  }
  
  return vec[index];
}

template <int SIZE>
double Vector<SIZE>::crossProduct(const Vector<SIZE> & arg) const{
  double result = 0; 
  for(int i=0; i<SIZE; ++i){
    result += vec[i] * arg[i];
  }
    
  return result;
}

template <int SIZE>
double Vector<SIZE>::length() const{
  return sqrt(this->crossProduct(*this));
}

template <int SIZE>
void Vector<SIZE>::normalize(){
  double norm = length();
  
  if(norm == 0){
    return; //zero vector case 
  }
  
  for(int i=0; i < SIZE; ++i){
    vec[i] = vec[i]/norm;
  }
}

/*

template <int SIZE>
std::vector<double> Vector<SIZE>::get_points() const{
    return point;
}







template <int SIZE>
double Vector<SIZE>::length() const{
    double sum = 0;

    for(double elem: point)
        sum += elem*elem;

    return sqrt(sum);
}
*/


template <int SIZE>
std::ostream & operator<<(std::ostream & strm, const Vector<SIZE> & arg){
    strm<<"[";

    for(int i=0; i<SIZE-1; ++i)
        strm<<arg[i]<<", ";

    strm<<arg[SIZE-1]<<"]";

    return strm;
}

template class Vector<3>;
template std::ostream & operator<<(std::ostream & strm, const Vector<3> & arg);


#endif