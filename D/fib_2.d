import std.stdio;
import std.algorithm;


int[] fib(int n){

  int[] fibs;
  fibs ~= 0;
  fibs ~= 1;

  for(int i=2; i<n; i++){
    fibs ~= (fibs[i-1]+fibs[i-2]);
  }
  return fibs;
}

void main(string[] args){

  auto series = fib(34);
  auto even = filter!(a => a % 2 == 0)(series);
  auto sum = reduce!((a,b) => a+b)(0,even);
  writeln(sum);
}