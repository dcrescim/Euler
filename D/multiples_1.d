import std.stdio;

void main(string[] args){

  int count = 0;
  for(int i = 0; i < 1000; i++){
    if ((i % 3 == 0) || (i % 5 ==0)){
      count += i;
    }
  }
  writeln(count);
  // Main can return a void in D! (behind the scenes it actually just returns 0) 
}