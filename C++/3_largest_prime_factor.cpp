#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

bool isPrime(long long numb){
  if(numb <= 1) return false;
  
  for(int i = 2; i <= sqrt(numb); i++){
    if (numb % i == 0) return false;
  }
  return true;
}

int largest_prime_factor(long long numb){

  int largest = 1;
  for(int i=2; i<= numb; i++){
    if ((numb % i == 0) && (isPrime(i))){
      largest = i;
      numb = numb /i;
      i--;
    }
  }

  return largest;
}

int main(){

  cout << largest_prime_factor(600851475143) << endl;

  return 0;
}