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


def triangle_factors(numb):

  first = prime_factorize(numb)
  second = prime_factorize(numb + 1)

  if 2 in first:
    first[2] = first[2]-1

  else:
    second[2] = second[2]-1

  
  first_numbs = reduce(operator.mul, map(lambda x: x+1, first.values()), 1)
  second_numbs = reduce(operator.mul, map(lambda x: x+1, second.values()), 1)

  return first_numbs * second_numbs


i = 2
while True:
  if (triangle_factors(i) > 500):
    print i*(i+1)/2
    break
  i += 1