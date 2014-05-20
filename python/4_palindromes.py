import os
import string
import itertools

# Checks to see if two iterables are equal
def equality(iter_1, iter_2):
  zipped = itertools.izip_longest(iter_1, iter_2)
  for (left, right) in zipped:
    if not left == right:
      return False
  return True

def isPalindrome(numb):
  numb_str = str(numb)
  iter_numb = iter(numb_str)
  reversed_numb = reversed(numb_str)
  return equality(iter_numb, reversed_numb)

max_so_far = 0
for i in range(10**2, 10**3):
  for j in range(10**2, 10**3):
    if isPalindrome(i*j):
      max_so_far = max(max_so_far, i*j)

print max_so_far