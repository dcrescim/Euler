var count = 0;
for(var i = 0; i < 1000; i++){
  if ((i % 3 === 0) || (i%5 === 0)){
    count += i;
  }
}

console.log(count);