import std.stdio;
import std.typetuple;
import std.typecons;

int[int] create_word_mappings(){
  int[int] map = [0 : 0,
                  1 : 3,
                  2 : 3,
                  3 : 5,
                  4 : 4,
                  5 : 4,
                  6 : 3,
                  7 : 5,
                  8 : 5,
                  9 : 4,
                  10 : 3,
                  11 : 6,
                  12 : 6,
                  13 : 8,
                  14 : 8,
                  15 : 7,
                  16 : 7,
                  17 : 9,
                  18 : 8,
                  19 : 8,
                  20 : 6,
                  30 : 6,
                  40 : 5,
                  50 : 5,
                  60 : 5,
                  70 : 7,
                  80 : 6,
                  90 : 6
                ];
  for(int i = 1; i < 10; i++){
    map[i*100] = map[i] + 10;
  }
  map[1000] = 3 + 8;
  return map;
}

int[] divmod(int numb, int val){
  int div = numb/val;
  int mod = numb % val;
  return [div, mod];
}

int get_numb_letters(int numb, int[int] map){
  int[] div_mod = divmod(numb, 100);
  int hundreds = div_mod[0];
  int tens_and_ones = div_mod[1];

  if (tens_and_ones < 20) {
    return map[hundreds*100] + map[tens_and_ones];
  }
  else{
    int[] div_holder = divmod(tens_and_ones, 10);
    int tens = div_holder[0];
    int ones = div_holder[1];
    return map[hundreds*100] + map[tens*10] + map[ones];
  }
}


void main(){

  int[int] map = create_word_mappings();

  int total = 0;
  for(int i = 1; i < 1000; i++){
    int val = get_numb_letters(i,map);
    total += val;
  }

  total += map[1000];
  writeln(total);

}