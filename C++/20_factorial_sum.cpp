#include <iostream>
#include <algorithm>
#include "../../ttmath-0.9.3/ttmath/ttmath.h"

using namespace std;

int sum_digits(ttmath::Int<40> numb){
  int total = 0;
  while(numb != 0){
    total += (numb % 10).ToInt();
    numb /= 10;
  }
  return total;
}

ttmath::Int<40> factorial(int numb){
  ttmath::Int<40> val = 1;
  while(numb > 1){
    val *= numb;
    numb -= 1;
  }
  return val;
}

int main(){
  cout << sum_digits(factorial(100)) << endl;
 
  return 0;
}