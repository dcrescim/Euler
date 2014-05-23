#include <iostream>
#include <cmath>

using namespace std;
int main(){

  for(int a=0; a <= 333; a++){
    for(int b=a+1; b < (1000-a)/2; b++){
      int c = 1000 -a-b;

      if(pow(a,2) + pow(b,2) == pow(c,2)){
        cout << a*b*c << endl;
      }
    }
  }


  return 0;
}