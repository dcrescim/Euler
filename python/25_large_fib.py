
fibs = []
fibs.append(0) # 1
fibs.append(1) # 2

while True:
  val = fibs[-2] + fibs[-1]
  if len(str(val)) >= 1000:
    break

  fibs.append(val)

fibs.append(val)
print len(fibs)
