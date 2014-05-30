#include <iostream>
#include <fstream>
#include <algorithm>
#include "../../ttmath-0.9.3/ttmath/ttmath.h"
#include <string>

using namespace std;

int main(){

  ttmath::Int<6> total = 0;

  ifstream file ("../data/13_loop_sum.txt");

  string line;
  while(getline(file, line)){
    ttmath::Int<6> val = line;
    total += val;
  }

  string total_string;
  total.ToString(total_string);
  cout << total_string.substr(0,10) << endl;

  return 0;
}