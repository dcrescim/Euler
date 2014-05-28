

word_mappings = {0 : 0,
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
                 90 : 6,
                };
for(var i = 1; i < 10; i++){
  word_mappings[i*100] = word_mappings[i] + 10
}

word_mappings[1000] = 3 + 8

function divmod(numb, val){
  var h = {};
  var div = Math.floor(numb / val);
  var mod = numb - div*val;
  h['div'] = div;
  h['mod'] = mod;
  return h;
}


function get_numb_letters(numb){
  var div_mod = divmod(numb, 100);
  var hundreds = div_mod['div'];
  var tens_and_ones = div_mod['mod'];

  if (tens_and_ones < 20) {
    return word_mappings[hundreds*100] + word_mappings[tens_and_ones];
  }
  else{
    var div_holder = divmod(tens_and_ones, 10);
    var tens = div_holder['div'];
    var ones = div_holder['mod'];
    return word_mappings[hundreds*100] + word_mappings[tens*10] + word_mappings[ones];
  }
}

var total = 0;
for(var i = 1; i < 1000; i++){
  var val = get_numb_letters(i);
  total += val;
}
total += word_mappings[1000];

console.log(total);