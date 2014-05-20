

function fib(n){

  var list = [];
  list.push(0);
  list.push(1);
  for(var i = 2; i < n; i++){
    list.push(list[i-1] + list[i-2]);
  }
  return list;
}

var list = fib(34);
var new_list = list.filter(function(x){return x % 2 == 0;});
var sum = new_list.reduce(function(pv, cv){ return pv+cv;}, 0);
console.log(sum);

