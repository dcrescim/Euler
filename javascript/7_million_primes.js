

function isPrime(numb){
  for(var i = 2; i <= Math.sqrt(numb); i++){
    if (numb % i == 0){
      return false;
    }
  }
  return true;
}


var count = 0
var numb = 2

while (true){
  if (isPrime(numb)){
    count += 1;
  }
  if (count == 10001){
    console.log(numb);
    break;
  }
  numb += 1;
}