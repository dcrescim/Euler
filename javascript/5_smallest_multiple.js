

function prime_factorize(numb){

  var prime_map = {};
  for(var i=2; i<=numb; i++){
    if(numb % i == 0){
      if (i in prime_map){
        prime_map[i] += 1;
      }
      else{
        prime_map[i] = 1;
      }
      numb /= i;
      i--;
    }
  }
  return prime_map;
}


function update(total, primes){

  for(var prime in primes){
    if(primes.hasOwnProperty(prime)){
      if (prime in total){
        total[prime] = Math.max(total[prime], primes[prime]);
      }
      else{
        total[prime] = primes[prime];
      }
    }
  }
}

var el = {};
var total = {};
for(var i=2; i <= 20; i++){
  el = prime_factorize(i);
  update(total, el);
}


var total_count = 1;
for(var prime in total){
  if(total.hasOwnProperty(prime)){
    total_count *= Math.pow(prime, total[prime]);
  }
}
console.log(total_count);

exports.prime_factorize = prime_factorize