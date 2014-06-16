

def change(n, coin_vals):

  if n == 0:
    return 1

  if ((coin_vals == []) or (n < 0)):
    return 0


  total = 0
  for i in range(len(coin_vals)):
    total += change(n-coin_vals[i], coin_vals[i:])
  return total


print change(200, [200,100,50,20,10,5,2,1])