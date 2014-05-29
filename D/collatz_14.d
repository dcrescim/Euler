import std.stdio;
import std.algorithm;
import std.conv;

long collatz(long numb, ref long[long] map){

  long orig = numb;
  int count = 0;

  while(numb != 1){

    if (numb in map){
      map[orig] = map[numb] + count;
      return map[orig];
    }
    if (numb % 2 == 0){
      numb /= 2;
    }
    else{
      numb = 3*numb + 1;
    }
    count += 1;
  }
  map[orig] = count;
  return map[orig];
}


void main(){

  
  long[long] map;
  long max_collatz = 0;
  int max_index = -1;

  for(int i=1; i < 1000000; i++){
    long val = collatz(i, map);
    if(val > max_collatz){
      max_collatz = val;
      max_index = i;
    }
  }
  writeln(max_index);
  
}