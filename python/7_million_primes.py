import os
import math

def isPrime(numb):
  for i in xrange(2,int(math.sqrt(numb))+1):
    if (numb % i == 0):
      return False
  return True


count = 0
numb = 2

while True:
  if isPrime(numb):
    count += 1
  if count == 10001:
    print numb
    break
  numb += 1
