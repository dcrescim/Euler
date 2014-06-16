

def repeating(d):
  while (d % 2 == 0):
    d /= 2
  while (d % 5 == 0):
    d /= 5

  if d == 1:
    return 0

  total = 1
  count = 0

  total = total*10 % d
  count += 1
  while (total != 1):
    total = total*10 % d
    count += 1
  
  return count

max_val = 0
index = 0
for i in xrange(1,1000):
  val = repeating(i)
  if val > max_val:
    max_val = val
    index = i

print index

