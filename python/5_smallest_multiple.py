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

def update(map1, map2):
  for elem in map2:
    map1[elem] = max(map1[elem], map2[elem])

total = defaultdict(int)
cur = defaultdict(int)
for i in xrange(2,20+1):
  cur = prime_factorize(i)
  update(total,cur)

total_count = 1
for elem in total:
  total_count *= pow(elem, total[elem])

print total_count