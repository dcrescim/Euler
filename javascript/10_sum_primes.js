
function isPrime(numb){
  for(var i=2; i<=Math.floor(Math.sqrt(numb)); i++){
    if (numb % i == 0){
      return false;
    }
  }
  return true;
}

var count = 10;
for(var p = 7; p < 2000000; p += 6){
  if (isPrime(p)) count += p;
  if (isPrime(p+4)) count += (p+4);
}
  
console.log(count);