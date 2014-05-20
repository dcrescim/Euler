import std.stdio;
import std.algorithm;
import std.math;

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

void update(ref int[int] total, const ref int[int] mapping){

  foreach(key, value; mapping){
    if (key in total){
      total[key] = max(total[key], value);
    }
    else{
      total[key] = value;
    }
  }
}

int main(string[] args){

  int[int] total;
  int[int] cur;
  for(int i=2; i<=20; i++){
    cur = prime_factorize(i);
    update(total, cur);
  }
  
  int total_count = 1;
  foreach(key, value; total){
    total_count *= pow(key,value);
  }
  writeln(total_count);

  return 0;
}