import math

def isPrime(numb):
  for i in xrange(2,int(math.sqrt(numb))+1):
    if (numb % i == 0):
      return False
  return True

def largest_prime_factor(big_numb):

  largest_prime_factor = 1

  for i in xrange(2, int(math.sqrt(big_numb))+ 1):
    if ((big_numb % i == 0) and isPrime(i)):
      largest_prime_factor = i

  return largest_prime_factor

print largest_prime_factor(600851475143)
