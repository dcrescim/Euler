import math
from collections import defaultdict
import operator

def prime_factorize(numb):
  primes = defaultdict(int)
  i = 2
  while(i <= numb):
    if (numb % i == 0):
      primes[i] += 1
      numb /= i
      i -= 1
    i += 1
  return primes

def geo_sum((num, pow)):
  return (num**(pow+1) - 1)/(num - 1)

def all_divisors_sum(prime_factors):
  return reduce(operator.mul, map(geo_sum, prime_factors.iteritems()), 1)

def proper_divisor_sum(numb):
  primes = prime_factorize(numb)
  total_sum = all_divisors_sum(primes)
  return total_sum - numb

abundant = set()
for i in xrange(2, 28124):
  if proper_divisor_sum(i) > i:
    abundant.add(i)

sums = set()
for i in abundant:
  for j in abundant:
    sums.add(i+j)

all = set(xrange(1,28124))
print sum(all - sums)
