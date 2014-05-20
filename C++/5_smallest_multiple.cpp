#include <iostream>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

map<int,int> prime_factorize(int numb){

  map<int, int> factors;

  for(int i=2; i <= numb; i++){

    if (numb % i == 0){
      factors[i] += 1;
      numb /= i;
      i--;
    }
  }
  return factors;
}

void update(map<int,int>& total, const map<int,int>& primes){

  for(auto it=primes.begin(); it != primes.end(); it++){
    total[it->first] = max(total[it->first], it->second);
  }
}


int main(int argc, char** argv){

  map<int,int> total;
  map<int,int> cur_factors;

  for(int i=2; i<=20; i++){
    cur_factors = prime_factorize(i);
    update(total, cur_factors);
  }

  int total_count = 1;
  for(auto it = total.begin(); it != total.end(); it++){
    total_count *= pow(it->first, it->second);
  }

  cout << total_count << endl;

  return 0;
}
