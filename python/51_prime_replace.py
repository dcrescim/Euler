import os
import math
import networkx as nx
import itertools
import pdb
G = nx.Graph()

def isPrime(numb):
  for i in xrange(2,int(math.sqrt(numb))+1):
    if (numb % i == 0):
      return False
  return True

def load_primes(filename):
  f = open(filename)
  primes = set(map(int, f.readline().split(',')))
  return primes


def difference_calc(prime_1, prime_2):
  #pdb.set_trace()
  diff = abs(prime_1 - prime_2)
  digit_list = list(str(diff))

  # Check to see if all nonzero elements are equal
  sd = filter(lambda x: x != '0', digit_list)
  if_no = (len(set(sd)) <= 1)
  return if_no


'''
h = filter(isPrime, xrange(11,100))

for elem in itertools.combinations(h, 2):
  print elem
'''