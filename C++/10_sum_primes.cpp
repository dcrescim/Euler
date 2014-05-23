#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool isPrime(long long numb){
  if(numb <= 1) return false;
  
  for(int i = 2; i <= sqrt(numb); i++){
    if (numb % i == 0) return false;
  }
  return true;
}

int main(){

  long long count = 10;
  for(int i=7; i< 2000000; i += 6){
    if (isPrime(i)) count += i;
    if (isPrime(i+4)) count += (i+4);
  }

  cout << count << endl;
  return 0;
}