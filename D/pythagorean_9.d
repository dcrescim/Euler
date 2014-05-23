import std.stdio;
import std.algorithm;
import std.conv;
import std.math;

void main(string[] args){

  for(int a = 2; a <= 333; a++){
    for(int b = a; b < (1000-a)/2; b++){
      int c = 1000 - a - b;
      if(pow(a,2) + pow(b,2) == pow(c,2)){
        writeln(a*b*c);
        break;
      }
    }
  }
}