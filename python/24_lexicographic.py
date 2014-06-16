import itertools

h = [0,1,2,3,4,5,6,7,8,9]

it = itertools.permutations(h)
for i in xrange(999999):
  h = it.next()

j = it.next()
print int(''.join(map(str, j)))
