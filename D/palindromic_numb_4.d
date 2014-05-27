import std.stdio;
import std.algorithm;
import std.conv;
import std.math;

bool isPalindrome(int numb){
  
  dchar[] orig = to!(dchar[])(numb);
  dchar[] rev = orig.dup;
  rev.reverse();
  return (orig == rev);

}

void main(){

  int max_so_far = 0;

  for(int i = pow(10,2); i < pow(10,3); i++){
    for(int j = pow(10,2); j < pow(10,3); j++){
      int val = i*j;
      if (isPalindrome(val)){
        max_so_far = max(max_so_far, val);
      }
    }
  }

  writeln(max_so_far);
}
