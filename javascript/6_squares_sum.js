

var n = 100;

// The sum of the first n squares is n*(2n+1)(n+1)/6
var sum_of_squares = n*(n+1)*(2*n+1)/6;

// The sum of the first n natural numbers is n*(n+1)/2
var square_of_sum = (n*(n+1)/2) * (n*(n+1)/2);

console.log(square_of_sum - sum_of_squares);