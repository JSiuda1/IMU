#include <iostream>
#include "matrix.h"
#include "quaternion.h"


int main(){
  Quaternion q(1,2,3,4);
  q.test();
  q.conjugate();
  q.test();
  q.normalize();
  q.test();

  return 1;
}