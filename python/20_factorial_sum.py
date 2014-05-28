
def sum_digits(numb):
  total = 0
  while numb != 0:
    i = numb % 10
    total += i

    numb = (numb - i)/10

  return total

def factorial(numb):
  total = 1
  while numb > 1:
    total *= numb
    numb -= 1
  return total

print sum_digits(factorial(100))