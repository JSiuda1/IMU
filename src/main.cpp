#include <iostream>
#include "matrix.h"

int main(){
  Matrix<3> test;
  //Matrix<3> test({{1,2,3}, {3, 2, 1}, {4, 5, 6}});
  Matrix<3> test2 = test;
  test.test();
  test2.test();
  //std::cout << "123" << std::endl;
  return 0;
}