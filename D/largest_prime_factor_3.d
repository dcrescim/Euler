import std.stdio;
import std.algorithm;
import std.conv;
import std.math;

int[int] prime_factorize(long numb){
  int[int] primes;

  for(int i=2; i<=numb; i++){
    if(numb % i == 0){
      primes[i] += 1;
      numb /= i;
      i--;
    }
  }
  return primes;
}


void main(string[] args){
  
  int[int] prime_factors = prime_factorize(600851475143);
  writeln(reduce!(max)(prime_factors.keys));

}
