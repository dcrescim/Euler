
function isPalindrome(numb){
  var numb_str = numb.toString();
  var reverse = numb_str.split('').reverse().join('');

  if (numb_str == reverse){
    return true;
  }
  else{
    return false;
  }
}

var max_so_far = 0;
for(var i = Math.pow(10,2); i < Math.pow(10,3); i++){
  for(var j = Math.pow(10,2); j < Math.pow(10,3); j++){
    var numb = i*j;
    if (isPalindrome(numb)){
      max_so_far = Math.max(max_so_far, numb);
    }
  }
}

console.log(max_so_far);

exports.isPalindrome = isPalindrome;
