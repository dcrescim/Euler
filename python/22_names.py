
def string_to_val(name):
  total = 0
  for el in name:
    total += ord(el) - ord("A") + 1

  return total

f = open("../data/names.txt")
line = f.readline().replace("\"","")
names = line.split(',')
names.sort()
name_values = map(string_to_val, names)
print name_values
total = 0
for (index, val) in enumerate(name_values) :
  total += index*val

print total
