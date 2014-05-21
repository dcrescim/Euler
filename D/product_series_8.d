import std.stdio;
import std.algorithm;
import std.conv;
import std.math;

void main(){
  auto f = File("numb_8.txt", "r");
  string line = f.readln();
  
  long[1000] numbs;
  foreach(index, c; line){
    numbs[index] = to!long(c-'0');
  }

  long max_so_far = 0;
  for(int i = 0; i < 1000- 13; i++){
    long val=reduce!((a,b) => a*b)(1L, numbs[i .. (i+13)]);
    max_so_far = max(max_so_far, val);
  }
  writeln(max_so_far);
}