#include <iostream>
#include <algorithm>
#include <boost/range/adaptors.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/algorithm.hpp>
#include <cmath>
using namespace std;

bool isPalindrome(int numb){

  string orig = to_string(numb);
  string rev;
  boost::copy(orig, std::back_inserter(rev));
  std::reverse(rev.begin(), rev.end());

  return (orig == rev);

}

int main(){

  int max_so_far = 0;
  for(int i = pow(10,2); i < pow(10,3); i++){
    for(int j = pow(10,2); j < pow(10,3); j++){
      int val = i*j;
      if (isPalindrome(val)){
        max_so_far = max(max_so_far, val);
      }
    }
  }
  cout << max_so_far << endl;

  return 0;
}
