#ifndef QUATERNION_HH
#define QUATERNION_HH

#include "vector.h"

class Quaternion{
  Vector q;

  public:
  Quaternion();
  Quaternion(std::initializer_list<double> arg);
  Quaternion(const double & w, const double & x, const double & y, const double & z);
  void conjugate();
  Quaternion operator*(const Quaternion & rhs) const;
  float dotProduct(const Quaternion & rhs) const;
  void normalize();
  void test();
};

Quaternion::Quaternion(){
  q = Vector(4);
}
/*
Quaternion::Quaternion(std::initializer_list<double> arg){
  q = Vector(4);
}*/

Quaternion::Quaternion(const double & w, const double & x, const double & y, const double & z){
  q = Vector({w,x,y,z});
}

void Quaternion::conjugate(){
  q[1] = -q[1];
  q[2] = -q[2];
  q[3] = -q[3];
}


Quaternion Quaternion::operator*(const Quaternion & rhs) const{
  Quaternion result;
  result.q[0] = q[0]*rhs.q[0] - q[1]*rhs.q[1] - q[2]*rhs.q[2] - q[3]*rhs.q[3];
  result.q[1] = q[0]*rhs.q[1] - q[1]*rhs.q[0] - q[2]*rhs.q[3] - q[3]*rhs.q[2];
  result.q[2] = q[0]*rhs.q[2] - q[1]*rhs.q[3] - q[2]*rhs.q[0] - q[3]*rhs.q[1];
  result.q[3] = q[0]*rhs.q[3] - q[1]*rhs.q[2] - q[2]*rhs.q[1] - q[3]*rhs.q[0];
  return result;
}

float Quaternion::dotProduct(const Quaternion & rhs) const{
  return q[0]*rhs.q[0] + q[1]*rhs.q[1] + q[2]*rhs.q[2] + q[3]*rhs.q[3];
}

void Quaternion::normalize(){
  q.normalize();
}



void Quaternion::test(){
  std::cout << q << std::endl;
}



#endif