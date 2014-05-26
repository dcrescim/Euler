import math
from collections import defaultdict

def prime_factorize(numb):
  primes = defaultdict(int)
  i = 2
  while(i <= int(math.sqrt(numb)) + 1):
    if (numb % i == 0):
      primes[i] += 1
      numb /= i
      i -= 1
    i += 1
  if numb > 1:
    primes[numb] += 1
  return primes

prime_factors = prime_factorize(600851475143)

print max(prime_factors.keys())
