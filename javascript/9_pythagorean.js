

for(var a= 2; a <= 333; a++){
  for(var b = a+1; b < (1000-a)/2; b++){
    var c = 1000 -a -b;

    if(Math.pow(a,2) + Math.pow(b,2) == Math.pow(c,2)){
      console.log(a*b*c);
      break;
    }

  }
}