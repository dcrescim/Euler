#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <cmath>
#include <functional>

using namespace std;

int digit(char d){return d - '0';}

int main(){

  ifstream myfile ("8_numb.txt");
  string line;

  getline(myfile, line);

  // I'm on a 32 bit machine, so I need 8 bytes to store this integer
  vector<long long> numbs;

  boost::copy(line | boost::adaptors::transformed(digit),
              back_inserter(numbs));
  
  long long max_so_far = 0;
  for(auto it = numbs.begin(); it + 13 != numbs.end(); it++){
    long long val = std::accumulate(it, it+13, 1LL, std::multiplies<long long>());
    max_so_far = max(max_so_far, val);
  }

  cout << max_so_far << endl;

  /*
  for(int i = 0; i < numbs.size() - 13; i++){
    long long total_val = 1;
    for(int j = i; j < i + 13; j++){
      total_val *= numbs[j];
    }
    cout << total_val << endl;
  }
  */

  return 0;
}
