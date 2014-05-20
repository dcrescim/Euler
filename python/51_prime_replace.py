import os


def load_primes(filename):
  f = open(filename)
  primes = set(map(int, f.readline().split(',')))
  return primes


primes= load_primes('../primes_smaller.txt')
print primes

for i in xrange(10**4, 10**5):