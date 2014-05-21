#include <algorithm>
#include <vector>
#include <iostream>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
using namespace std;

vector<int> fib(int n){

  vector<int> fibs;
  fibs.push_back(0);
  fibs.push_back(1);

  for(int i=2; i< n; i++){
    fibs.push_back(fibs[i-1]+fibs[i-2]);
  }

  return fibs;
}

bool isOdd (int i){ return (i%2 == 1);}

int main(){

  int total_count = 0;
  vector<int> series = fib(34);

  // I like the LINQ way of expressing these sort of data-flow patterns
  // This is my attempt to get close to that
  int value = boost::accumulate(series | 
                  boost::adaptors::filtered(isOdd), 0);

  /*
  for (int i=0; i< series.size(); i++){
    if(isOdd(series[i])){
      total_count += series[i];
    }
  }*/


  cout << value << endl;

  return 0;
}