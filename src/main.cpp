#include <iostream>
#include "matrix.h"
#include "vector.h"


int main(){
  Matrix test{{1,2}, {3,4}};
  Vector testv{9,9,9};
  Matrix res(2,1);
  
  for(int i=0; i<2; i++){
    std::cout << test[i] << std::endl;
  }
  
  for(int i=0; i<2; i++){
    test[i] = testv;
  }

  for(int i=0; i<2; i++){
    std::cout << test[i] << std::endl;
  }

  return 1;
}