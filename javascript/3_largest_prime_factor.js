

function isPrime(numb){
  for(var i=2; i<=Math.floor(Math.sqrt(numb)); i++){
    if (numb % i == 0){
      return false;
    }
  }
  return true;
}


function largest_prime_factor(big_numb){
  largest_prime_factor = 1;
  for(var i=2; i<=Math.floor(Math.sqrt(big_numb)); i++){

    if((big_numb % i ==0) && (isPrime(i))){
      largest_prime_factor = i;
    }
  }
  return largest_prime_factor;
}

exports.isPrime = isPrime;
exports.largest_prime_factor = largest_prime_factor;

console.log(largest_prime_factor(600851475143))
