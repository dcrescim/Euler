
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

var prime_factors = prime_factorize(600851475143);
console.log(Math.max.apply(Math,prime_factors.keys()));
