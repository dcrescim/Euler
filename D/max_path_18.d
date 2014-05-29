import std.stdio;
import std.string;
import std.array;
import std.algorithm;
import std.conv;

int[][] read_grid(string filename){
  auto f = File(filename);
  int[][] grid;

  foreach(line; f.byLine){
    int[] line_numbs = array(map!(to!int)(splitter(line, ' ')));
    grid ~= line_numbs;
  }
  return grid;
}

int greater(int a , int b){
  if (a > b){ return a;}
  return b;
}

void main(){

  int[][] grid = read_grid("../data/18_max_path_1.txt");
  int[][] max_grid;

  for(int i = 0; i < 15; i++){
    int[] grid_level;
    for(int j = 0; j <= i; j++){
      int elem = grid[i][j];
      int above;
      int above_left;
      try{
        above = max_grid[i-1][j];
      }
      catch{
        above = 0;
      }

      try{
        above_left = max_grid[i-1][j-1];
      }
      catch{
        above_left = 0;
      }

      grid_level ~= (elem + max(above, above_left));
    }
    max_grid ~= grid_level;
  }

  writeln(reduce!(greater)(0,max_grid[$-1]));
}