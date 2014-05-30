#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
typedef long long longer;

longer collatz(longer numb, map<longer, longer> coll){
  longer orig = numb;
  int count = 0;

  while(numb != 1){
    if(coll.find(numb) != coll.end()){
      coll[orig] = coll[numb] + count;
      return coll[orig];
    }
    if (numb % 2 == 0){
      numb /= 2;
    }
    else{
      numb = numb* 3+ 1;
    }
    count += 1;
  }
  coll[orig] = count;
  return coll[orig];
}

int main(){

  map<longer, longer> coll;
  longer max_collatz = 0;
  int max_index = -1;

  for(int i=1; i<1000000; i++){
    longer val = collatz(i, coll);
    if(val > max_collatz){
      max_collatz = val;
      max_index = i;
    }
  }

  cout << max_index << endl;

  return 0;
}