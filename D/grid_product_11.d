import std.stdio;
import std.algorithm;
import std.conv;
import std.math;
import std.array;

int[][][] get_neighbor_list(int i, int j){
  int[][][] neighbors = [
    [[i, j],[i+1, j],[i+2,j], [i+3,j]], // South
    [[i, j],[i-1, j],[i-2,j], [i-3,j]], // North
    [[i, j],[i, j+1],[i,j+2], [i,j+3]], // West
    [[i, j],[i, j-1],[i,j-2], [i,j-3]], // East
    [[i, j],[i+1, j+1],[i+2,j+2], [i+3,j+3]], // Southwest
    [[i, j],[i-1, j-1],[i-2,j-2], [i-3,j-3]], // Northeast
    [[i, j],[i+1, j-1],[i+2,j-2], [i+3,j-3]], // Southeast
    [[i, j],[i-1, j+1],[i-2,j+2], [i-3,j+3]] // Northwest
  ];
  return neighbors;
}

int[][] grab_grid(string filename){
  File f = File(filename, "r");
  int[][] grid;

  foreach(str; f.byLine){
    int [] numbs = array(map!(to!(int))(splitter(str, " ")));
    grid ~= numbs;
  }
  return grid;
}

int check_grid(int[][] grid, int[][] direction){

  int total = 1;
  for(int k =0; k < direction.length; k++){
    int[] point = direction[k];
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

void main(string[] args){

  auto grid = grab_grid("../data/11_grid_product.txt");

  int max_total = 0;

  for(int i = 0; i < 20; i++){
    for(int j = 0; j < 20; j++){
      auto neighbor_lists = get_neighbor_list(i,j);
      for(int k = 0; k < neighbor_lists.length; k++){
        int total = check_grid(grid, neighbor_lists[k]);
        max_total = max(max_total, total);
      }
    }
  }

  writeln(max_total);
}
