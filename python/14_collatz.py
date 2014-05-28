

def collatz(numb, collatz_map):
  orig_numb = numb

  count = 0
  while numb != 1:
    if numb in collatz_map:
      collatz_map[orig_numb] = collatz_map[numb] + count
      return collatz_map[numb] + count
    if (numb % 2 == 0):
      numb /= 2
    else:
      numb = 3*numb+1
    count += 1

  collatz_map[orig_numb] = count
  return count

collatz_map = {}
max_collatz = 0
max_index = -1
for i in range(1, 1000000):
  val = collatz(i,collatz_map)
  if val > max_collatz:
    max_collatz = val
    max_index = i
print max_index
