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

void main(){

  int count = 0;
  int numb = 2;

  while (true){
    if (isPrime(numb)){
      count += 1;
    }
    if (count == 10001){
      writeln(numb);
      break;
    }
    numb += 1;
  }

}