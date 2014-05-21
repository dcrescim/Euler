fs = require('fs');

function convertInt(element){
  return parseInt(element, 10);
}

var data = fs.readFileSync('8_numb.txt', 'utf-8');

data = data.split('')

var numbs = data.map(convertInt)

var max_value = 1;
for(var i = 0; i < 1000-13; i++){
  var small = numbs.slice(i, i+13);
  var value = small.reduce(function(a,b){return a*b}, 1); 
  max_value = Math.max(max_value, value);
}

console.log(max_value);