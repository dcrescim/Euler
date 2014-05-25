import copy

def sum_digits(numb):
  local_numb = copy.copy(numb)
  total = 0
  while local_numb != 0:
    i = local_numb % 10
    total += i

    local_numb = (local_numb - i)/10

  return total


print sum_digits(2**1000)