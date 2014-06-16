

def digit_fifth_power(numb):
  total = 0
  while(numb != 0):
    dig = numb % 10
    numb = (numb - dig)/10
    total += dig ** 5
  return total

total = 0
for i in range(10, 10**6):
  if(digit_fifth_power(i) == i):
    #print i
    total += i

print total