#include <iostream>
#include <algorithm>
#include <boost/range/adaptors.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/algorithm/string.hpp>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

vector<vector<vector<int>>> get_neighbor_list(int i, int j){
  vector<vector<vector<int>>> neighbors = {
    {{i, j},{i+1, j},{i+2,j}, {i+3,j}}, // South
    {{i, j},{i-1, j},{i-2,j}, {i-3,j}}, // North
    {{i, j},{i, j+1},{i,j+2}, {i,j+3}}, // West
    {{i, j},{i, j-1},{i,j-2}, {i,j-3}}, // East
    {{i, j},{i+1, j+1},{i+2,j+2}, {i+3,j+3}}, // Southwest
    {{i, j},{i-1, j-1},{i-2,j-2}, {i-3,j-3}}, // Northeast
    {{i, j},{i+1, j-1},{i+2,j-2}, {i+3,j-3}}, // Southeast
    {{i, j},{i-1, j+1},{i-2,j+2}, {i-3,j+3}} // Northwest
  };

  return neighbors;
}

vector<vector<int>> grab_grid(string filename){
  ifstream f (filename);
  vector<vector<int>> grid;

  string line;
  while(getline(f, line)){
    vector<string> strs;
    boost::split(strs, line, boost::is_any_of(" "));
    
    vector<int> numbs; 
    boost::copy(strs | boost::adaptors::transformed([](string s){
      return stoi(s);
    }), back_inserter(numbs));
    
    /* Why can't I do this?
    vector<int> numbs = strs | boost::adaptors::transformed([](string s){
      return stoi(s);
    });
    */
    grid.push_back(numbs);
  }
  return grid;
}

int check_grid(vector<vector<int>> grid, vector<vector<int>> direction){

  int total = 1;
  for(int k =0; k < direction.size(); k++){
    vector<int> point = direction[k];
    int i = point[0];
    int j = point[1];

    if ((i < 0) || (i >= 20) || (j < 0) || (j >= 20)){
      return 0;
    }
    else{
      total *= grid[i][j];
    }    
  }
  return total;

}


int main(){

  auto grid = grab_grid("../data/11_grid_product.txt");
  int max_total = 0;

  for(int i = 0; i < 20; i++){
    for(int j = 0; j < 20; j++){
      auto neighbor_lists = get_neighbor_list(i,j);
      for(int k = 0; k < neighbor_lists.size(); k++){
        int total = check_grid(grid, neighbor_lists[k]);
        max_total = max(max_total, total);
      }
    }
  }

  cout << max_total << endl;


  return 0;
}
