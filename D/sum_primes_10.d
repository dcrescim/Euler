import std.stdio;
import std.algorithm;
import std.math;
import std.conv;

bool isPrime(int numb){

  for(int i=2; i<= sqrt(to!float(numb)); i++){
    if (numb % i == 0) return false;
  }
  return true;
}

void main(string[] args){

 long count = 10;

  for(int p = 7; p < 2000000; p += 6){
    if (isPrime(p)) count += p;
    if (isPrime(p+4)) count += (p+4);
  }
  
  writeln(count);
}