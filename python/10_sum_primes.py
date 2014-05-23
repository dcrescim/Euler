import math

def isPrime(numb):
  for i in xrange(2,int(math.sqrt(numb))+1):
    if (numb % i == 0):
      return False
  return True


count = 10
for p in xrange(7,2000000,6):
  if isPrime(p): count += p
  if isPrime(p+4): count += (p+4)

print count