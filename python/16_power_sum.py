
def sum_digits(numb):
  total = 0
  while numb != 0:
    i = numb % 10
    total += i

    numb = (numb - i)/10

  return total


print sum_digits(2**1000)