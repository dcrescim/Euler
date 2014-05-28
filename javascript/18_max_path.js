var fs = require('fs');

function convertInt(x){
  return parseInt(x, 10);
}

function read_grid(filename){
  var f = fs.readFileSync(filename);
  var grid = [];

  var text = f.toString().split('\n');
  text.forEach(function(line){
    var line_numbs = line.split(' ').map(convertInt);
    grid.push(line_numbs);
  });

  return grid;
}

var grid = read_grid("../data/18_max_path_1.txt");
var max_grid = [];

for(var i = 0; i < 15; i++){
  var grid_level = [];
  for(var j = 0; j <= i; j++){
    var elem = grid[i][j];
    var above = 0;
    var above_left = 0;
    previous_row = max_grid[i-1];
    if(typeof previous_row != 'undefined'){
      above = previous_row[j];
      above_left = previous_row[j-1];
      if (typeof above == 'undefined'){ above = 0;}
      if (typeof above_left == 'undefined'){above_left = 0;}
    } 
    grid_level.push(elem + Math.max(above, above_left));    
  }
  max_grid.push(grid_level)
}

console.log(Math.max.apply(Math, max_grid[14]));