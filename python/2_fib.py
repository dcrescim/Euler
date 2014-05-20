

def fib(n):
  fibs = []
  fibs.append(0)
  fibs.append(1)
  for i in xrange(2,n):
    fibs.append(fibs[i - 2] + fibs[i-1])

  return fibs

series = fib(34)
series = filter(lambda x: x %2 == 0, series)

print sum(series)