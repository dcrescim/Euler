var big = require("../../big.js/big.js");

function factorial(numb){
  var total = new big(1);
  while(numb > 1){
    total = total.times(numb);
    numb -= 1;
  }

  return total;
}

var fact = factorial(100);
console.log(fact.c.reduce(function(a,b){return a+b;}, 0));
