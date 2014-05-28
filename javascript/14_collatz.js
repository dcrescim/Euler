

function collatz(numb, collatz_map){
  var orig = numb;

  var count = 0;
  while (numb != 1){
    if (numb in collatz_map){
      collatz_map[orig] = collatz_map[numb] + count
      return collatz_map[orig]
    }
    if (numb % 2 == 0){
      numb /= 2;
    }
    else{
      numb = 3*numb + 1;
    }
    count += 1;
  }
  collatz_map[orig] = count;
  return count;
}

collatz_map = {};
max_collatz = 0;
max_index = -1;
for(var i = 1; i <= 1000000; i++){
  var val = collatz(i, collatz_map);
  if (val > max_collatz){
    max_collatz = val;
    max_index = i;
  }
}
console.log(max_index);