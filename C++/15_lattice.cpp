#include <iostream>
#include <algorithm>


using namespace std;

long long choose(int numerator, int denominator){
  double total = 1.0;

  while(denominator != 0){
    total *= numerator/static_cast<double>(denominator);
    numerator -= 1;
    denominator -= 1;
  }

  return static_cast<long long>(total);
}

int main(){
  cout << choose(40,20) << endl;
  return 0;
}