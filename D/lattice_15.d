import std.stdio;
import std.bigint;
import std.conv;

/*
This is a very famous math problem, and
it is basically asking us for the number
40_C_20 or (40 choose 20)
*/

long choose(int numerator, int denominator){

  double total = 1.0;
  while (denominator != 0){
    total *= numerator/to!double(denominator);
    numerator -= 1;
    denominator -= 1;
  }

  return to!long(total);

}

void main(){
  writeln(choose(40,20));
}