import std.stdio;
import std.algorithm;
import std.conv;
import std.bigint;
import std.string;
void main(string [] args){

  auto f = File("../data/13_loop_sum.txt");
  BigInt total  = "0";

  foreach(line; f.byLine){
    BigInt val = line;
    total += val;
  }

  writeln(to!string(total)[0..10]);

}