import math

'''
This is a very famous math problem, and
it is basically asking us for the number
40_C_20 or (40 choose 20)
'''

def choose(numerator, denominator):

  total = 1.0
  while denominator != 0:
    total *= float(numerator)/float(denominator)
    numerator -= 1
    denominator -= 1

  return int(total)


print choose(40,20)