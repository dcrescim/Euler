import std.stdio;
import std.algorithm;
import std.conv;

int[int] prime_factorize(int numb){
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

int increment(int x){ return x+1;}
int mul(int x,int y){return x*y;}

long triangle_factorize(int numb){

  auto first = prime_factorize(numb);
  auto second = prime_factorize(numb+1);

  if (2 in first){
    first[2] -= 1;
  }
  else{
    second[2] -= 1;
  }

  int val1 = reduce!(mul)(1, map!(increment)(first.values));
  int val2 = reduce!(mul)(1, map!(increment)(second.values));

  return val1*val2;
}


void main(){

  int i=2;
  while(true){
    writeln("i:", i, "|triangle:", triangle_factorize(i));
    if (triangle_factorize(i) > 500){
      writeln(i*(i+1)/2);
      break;
    }
    i += 1;
  }
}