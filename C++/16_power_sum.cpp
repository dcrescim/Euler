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


int main(){
  ttmath::Int<40> numb {2};
  numb.Pow(1000);

  cout << sum_digits(numb) << endl;
 
  return 0;
}