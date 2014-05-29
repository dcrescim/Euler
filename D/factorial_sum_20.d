import std.stdio;
import std.bigint;
import std.algorithm;

int sum_digits(BigInt a){
  int total = 0;
  while (a != 0){
    total += a % 10;
    a = a/10;
  }
  return total;
}

BigInt factorial(int numb){

  BigInt a = 1;
  while(numb > 1){
    a *= numb;
    numb -= 1;
  }
  return a;
}


void main(){

  writeln(sum_digits(factorial(100)));
}