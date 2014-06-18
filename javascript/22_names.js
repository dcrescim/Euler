var fs = require('fs');

function string_to_val(name){

  var begin = "A"
  var charCode_A = begin.charCodeAt(0);
  var total = 0;

  for(var i =0; i<name.length; i++){
    total += name.charCodeAt(i) - charCode_A + 1;
  }
  return total;
}

var f = fs.readFileSync("../data/names.txt");
var names = f.toString().replace(/\"/g, "");
names = names.split(",");
names.sort();
name_values = names.map(string_to_val);

var total = 0;
for(var i=0; i < name_values.length; i++){
  total += i*name_values[i];
}
console.log(total);


exports.string_to_val = string_to_val;