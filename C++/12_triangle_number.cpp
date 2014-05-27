#include <iostream>
#include <map>
#include <vector>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>

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

int increment(int x){return x+1;}
//int grab_second(pair<int,int> value){return value.second;}

int triangle_number(int numb){

  map<int,int> first = prime_factorize(numb);
  map<int,int> second = prime_factorize(numb+1);
  
  if (first.find(2) != first.end()){
    first[2] -= 1;
  }
  else{
    second[2] -= 1;
  }

  int val1 = boost::accumulate(first  |  boost::adaptors::map_values
                                      |  boost::adaptors::transformed(increment)
                                      , 1, std::multiplies<int>());
  

  int val2 = boost::accumulate(second |  boost::adaptors::map_values
                                      |  boost::adaptors::transformed(increment)
                                      , 1, std::multiplies<int>());
  
  return val1 * val2;
}


int main(){

  int i = 2;

  while (true){
    if (triangle_number(i) > 500){
      cout << i*(i+1)/2 << endl;
      break;
    }
    i += 1;
  }

  return 0;
}














