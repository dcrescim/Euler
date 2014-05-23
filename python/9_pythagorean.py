import os

'''
What we know, we know that a < b < c

Limits on a:
  1. The max value a can achieve (if
  a+b+c = 1000) is 333.

Limits on b:
  1. b must be greater than a
  2. because c must be greater than b, 
    the max value b can have is ((1000-a)/2)
'''

for a in range(2, 333):
  for b in range(a+1, (1000-a)/2):
    c = 1000 - a - b
    if (a**2 + b**2 == c**2):
      print a*b*c
      break

