import math
'''
First we solve the equation

12345*math.floor(log_2(x)) < x -1
'''

def calc(x):
  return 12345*math.floor(math.log(x)/math.log(2)) < x - 1

def calc2(x, y):
  return x <= math.floor((math.sqrt(4*y + 1) - 1)/2.0)

x = 2
while True:
  if calc(x):
    print x
    break
  x += 1

'''
x = 209867
'''
val = 209867
start_m = 44044367556 + 100
while True:
  if not calc2(val, start_m):
    print start_m
    break
  start_m -= 1

