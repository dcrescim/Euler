#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int numb){

  for(int i=2; i <= sqrt(numb);i++){
    if (numb % i == 0) return false;
  }
  return true;
}

int main(){
  int numb = 2;
  int count = 0;

  while (true){
    if (isPrime(numb)){
      count += 1;
    }
    if (count == 10001){
      cout << numb << endl;
      break;
    }
    numb += 1;
  }
  return 0;
}