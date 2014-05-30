#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){

  map<int,int> months = { {1 , 31},
                          {2 , 28},
                          {3 , 31},
                          {4 , 30},
                          {5 , 31},
                          {6 , 30},
                          {7 , 31},
                          {8 , 31},
                          {9 , 30},
                          {10, 31},
                          {11, 30},
                          {12, 31}
                        };
  int start_day = 2;
  int count = 0;

  for(int year = 1901; year <=2000; year++){
    for(int month = 1; month <= 12; month++){
      if((month == 2) && (year % 4 == 0)){
        start_day += months[2]+1;
      }
      else{
        start_day += months[month];
      }

      start_day = start_day % 7;
      if(start_day == 0){
        count +=1;
      }
    }
  }

  cout << count  << endl;
  return 0;
}