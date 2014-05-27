import std.stdio;
import std.algorithm;
import std.conv;
import std.math;
import std.array;

void main(){
  auto f = File("../data/8_product_series.txt", "r");
  string line = f.readln();
  
  long[] numbs = array(map!(a => to!long(a - '0'))(line));

  long max_so_far = 0;
  for(int i = 0; i < 1000- 13; i++){
    long val=reduce!((a,b) => a*b)(1L, numbs[i .. (i+13)]);
    max_so_far = max(max_so_far, val);
  }
  writeln(max_so_far);
}