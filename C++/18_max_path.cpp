#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <boost/algorithm/string.hpp>

#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>

using namespace std;

int convert(string numb){
  return stoi(numb);
}

vector<vector<int>> read_grid(string filename){
  ifstream myfile {filename};
  vector<vector<int>> grid;

  string line;
  while(getline(myfile, line)){
    vector<int> line_numbs;
    vector<string> strs;

    boost::split(strs, line, boost::is_any_of(" "));
    boost::copy(strs | boost::adaptors::transformed(convert), back_inserter(line_numbs));
    
    grid.push_back(line_numbs);
  } 
  return grid;
}

int int_greater(int a, int b){
  if(a > b) return a;
  return b;
}

int main(){
  vector<vector<int>> grid = read_grid("../data/18_max_path_1.txt");
  vector<vector<int>> max_grid;

  for(int i =0; i < 15; i++){
    vector<int> grid_level;
    for(int j = 0; j <= i; j++){
      int elem = grid[i][j];
      int above;
      int above_left;
      
      try{
        above = max_grid.at(i-1).at(j);
      }
      catch(...){
        above= 0;
      }

      try{
        above_left = max_grid.at(i-1).at(j-1);
      }
      catch(...){
        above_left = 0;
      }
      
      grid_level.push_back(elem + max(above, above_left));
    }
    max_grid.push_back(grid_level);
  }

  cout << boost::accumulate(max_grid[14], 0, int_greater) << endl;

  return 0;
}