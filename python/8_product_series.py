import os
import operator

f = open('../data/8_product_series.txt')
numb_str = f.readline()

ints = map(int, list(numb_str))

max_product = 1
for i in xrange(0, 1000-13):
  cur = ints[i:i+13]
  product = reduce(operator.mul, cur, 1)  
  max_product = max(max_product, product)

print max_product