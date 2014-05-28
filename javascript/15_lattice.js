

/*
This is a very famous math problem, and
it is basically asking us for the number
40_C_20 or (40 choose 20)
*/

function choose(numerator, denominator){
  var total = 1.0;
  while (denominator != 0){
    total *= numerator/denominator;
    numerator -= 1;
    denominator -= 1;
  }
  return parseInt(total, 10)
}

console.log(choose(40,20));