
Object.prototype.keys = function(){
  var keys = [];
  for(el in this){
    if (this.hasOwnProperty(el)){
      keys.push(el);
    }
  }
  return keys;
};

Object.prototype.values = function(){
  var values = [];
  for(el in this){
    if (this.hasOwnProperty(el)){
      values.push(this[el]);
    }
  }
  return values;
};

Object.prototype.iteritems = function(){
  var key_val_pairs = [];
  for(el in this){
    if (this.hasOwnProperty(el)){
      var key_val = [];
      key_val.push(el);
      key_val.push(this[el]);
      key_val_pairs.push(key_val);
    }
  }
  return key_val_pairs;
}

function prime_factorize(numb){

  var prime_map = {};
  for(var i=2; i<=Math.sqrt(numb); i++){
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
  if(numb > 1){

    if (numb in prime_map){
      prime_map[numb] += 1;
    }
    else{
      prime_map[numb] = 1;
    }
  }
  return prime_map;
}



function geo_sum(arr){
  return (Math.pow(arr[0], arr[1]+1) - 1)/ (arr[0] - 1);
}

function all_divisors_sum(prime_factors){

  return prime_factors.iteritems().map(geo_sum).reduce(function(a,b){return a*b;}, 1);

}

function proper_divisor_sum(numb){
  primes = prime_factorize(numb);
  total_sum = all_divisors_sum(primes);
  return total_sum - numb;
}

var count = 0;
for(var i = 2; i < 10000; i++){
  var val = proper_divisor_sum(i);
  if(proper_divisor_sum(val) == i){
    count += i;
  }
}
console.log(count);