var big = require('../../big.js/big.js');

var numb = new big(2);
numb = numb.pow(1000);

digit_sum = numb.c.reduce(function(a,b)
{
  return a+b;
}, 0);

console.log(digit_sum);