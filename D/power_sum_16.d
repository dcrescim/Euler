import std.stdio;
import std.bigint;
import std.math;

int sum_digits(BigInt a){
  int total = 0;
  while (a != 0){
    total += a % 10;
    a = a/10;
  }
  return total;
}

void main(){

  BigInt a = "2";
  a = a^^1000;

  writeln(sum_digits(a));



}