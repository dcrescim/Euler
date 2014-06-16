import math

def left_diag(n):
  return (n+1)*n*(n-1)/3 + n

def right_diag(n):
  return n*(2*n+1)*(n+1)/6 + math.floor(n/2)

def both_diag(n):
  return int(left_diag(n) + right_diag(n) - 1)

print both_diag(1001)