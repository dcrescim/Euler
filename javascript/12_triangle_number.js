

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

function increment(x){
  return x+1;
}

function multiply(a,b){
  return a*b;
}

function triangle_factorize(numb){

  var first = prime_factorize(numb);
  var second = prime_factorize(numb + 1);

  if (2 in first){
    first[2] -= 1;
  }
  else{
    second[2] -= 1;
  }

  var first_exp = [];
  for(var el in first){
    if (first.hasOwnProperty(el)){
      first_exp.push(first[el]);
    }
  }

  var second_exp = [];
  for(var el in second){
    if (second.hasOwnProperty(el)){
      second_exp.push(second[el]);
    }
  }

  var div1 = first_exp.map(increment).reduce(multiply, 1);
  var div2 = second_exp.map(increment).reduce(multiply,1);

  return div1*div2;

}


var i = 2;
while (true){

  if(triangle_factorize(i) > 500){
    console.log(i*(i+1)/2);
    break;
  }
  i += 1;
}

