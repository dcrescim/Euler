import math

def isPrime(numb):
  if numb <= 1:
    return False

  for i in xrange(2,int(math.sqrt(numb))+1):
    if (numb % i == 0):
      return False
  return True

max_count = 0
tuple_holder = (0,0)
for a in range(-999, 1000):
  for b in range(-999, 1000):
    n = 0
    count = 0
    while (isPrime(n**2 + a*n + b)):
      n += 1
      count += 1

    if count > max_count:
      max_count = count
      tuple_holder = (a,b)

print tuple_holder[0]*tuple_holder[1]