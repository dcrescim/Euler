var fs = require('fs');
// This solution uses the big.js library for arbitrary precision math
var big = require('../../big.js/big.js');

var f = fs.readFileSync("../data/13_loop_sum.txt");
var text = f.toString().split('\n');

var total_sum = new big(0);
text.forEach(function(line){
  total_sum = total_sum.plus(line);
})

console.log(total_sum.c.slice(0,10).join(''));

