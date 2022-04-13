#include <iostream>
#include "matrix.h"
#include "vector.h"


int main(){
  Matrix test{{1,1}, {1,1}};
  Matrix test2{{2,2}, {2,2}};
  
  test.test();
  test2.test();

  //(test2 + test).test();
  
  test = test2 + test;
  test.test();
  test2.test();
  std::cout << "XD" << std::endl;
  test2 + test2;
  std::cout << "XD" << std::endl;
  test2.test();
  return 0;
}