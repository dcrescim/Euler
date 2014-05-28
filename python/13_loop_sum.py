
f = open('../data/13_loop_sum.txt')
sum = 0
for line in f.readlines():
  sum += int(line)

print str(sum)[:10]