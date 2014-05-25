fs = require("fs");

function convertInt(element){
  return parseInt(element, 10);
}

function get_neighbor_list(i,j){
  var neighbors = [];
  neighbors.push([[i, j],[i+1, j],[i+2,j], [i+3,j]]); // South
  neighbors.push([[i, j],[i-1, j],[i-2,j], [i-3,j]]); // North
  neighbors.push([[i, j],[i, j+1],[i,j+2], [i,j+3]]); // West
  neighbors.push([[i, j],[i, j-1],[i,j-2], [i,j-3]]); // East
  neighbors.push([[i, j],[i+1, j+1],[i+2,j+2], [i+3,j+3]]); // Southwest
  neighbors.push([[i, j],[i-1, j-1],[i-2,j-2], [i-3,j-3]]); // Northeast
  neighbors.push([[i, j],[i+1, j-1],[i+2,j-2], [i+3,j-3]]); // Southeast
  neighbors.push([[i, j],[i-1, j+1],[i-2,j+2], [i-3,j+3]]); // Northwest

  return neighbors;
}

function check_grid(grid, neighbor_list){

  var total = 1;  
  //console.log(neighbor_list);
  for (var k=0; k < neighbor_list.length; k++){
    
    var point = neighbor_list[k];
    var i = point[0];
    var j = point[1];
    //console.log(i);
    //console.log(j);

    if ((i < 0) || (i >= 20) || (j < 0) || (j >= 20)){
      return 0;
    }
    else{
      total *= grid[i][j];
    }
  }
  return total;
}

function grab_grid(filename){
  var f = fs.readFileSync(filename);
  var grid = [];

  var text = f.toString().split('\n');
  text.forEach(function(line){
    var numbs = line.split(' ').map(convertInt);
    grid.push(numbs);
  });

  return grid;
}


var grid = grab_grid('../data/11_grid_product.txt');
var max_total = 0;

for(var i = 0; i < 20; i++){
  for(var j = 0; j < 20; j++){
    var neighbors = get_neighbor_list(i,j);
    for(var k = 0; k < neighbors.length; k++){
      //console.log(neighbors[i]);
      var total = check_grid(grid, neighbors[k]);
      max_total = Math.max(max_total, total);
    }
  }
}

console.log(max_total);
exports.get_neighbor_list = get_neighbor_list;
exports.check_grid = check_grid;
exports.grab_grid = grab_grid;

