#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <math.h>

using namespace std;


vector<int> read_primes(const string& filename){
  // Read in the file
  ifstream infile(filename.c_str());
  
  // Read the whole thing into line
  string line;
  getline(infile, line);

  // Split line into strs
  vector<string> strs;
  boost::split(strs, line, boost::is_any_of(","));

  vector<int> primes;
  for(int i = 0; i < strs.size(); i++){
    int val = atoi(strs[i].c_str());
    primes.push_back(val);
  }
  return primes;
}

int prime_factors(int numb, const vector<int>& primes){

  int total_count = 0;

  for(int i=0; i < primes.size(); i++){
    if (numb % primes[i] == 0){
      total_count += 1;
    }

    if (primes[i] > numb) break;
  }
  return total_count;

}




int main(){

  std::string file = "primes_smaller.txt";
  vector<int> primes = read_primes(file);

  int run = 0;
  for(int i=0; i < 10000000; i++){
    if (prime_factors(i, primes) == 4){
      run += 1;
    }
    else{
      run = 0;
    }

    if (run >=4){
      cout << i << endl;
      break;
    }
  }

  return 0;
}