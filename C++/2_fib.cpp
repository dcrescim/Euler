#include <algorithm>
#include <vector>
#include <iostream>

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
  
  for (int i=0; i< series.size(); i++){
    if(isOdd(series[i])){
      total_count += series[i];
    }
  }


  cout << total_count << endl;

  return 0;
}