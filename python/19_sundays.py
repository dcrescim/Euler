
months = {
          1 : 31,
          2 : 28,
          3 : 31,
          4 : 30,
          5 : 31,
          6 : 30,
          7 : 31,
          8 : 31,
          9 : 30,
          10: 31,
          11: 30,
          12: 31
}

# Jan 1 1901 was on a Tuesday
start_day = 2
count = 0

for year in xrange(1901, 2001):
  for month in xrange(1,13):
    if ((month == 2) and (year % 4 == 0)):
      start_day += months[2] + 1
    else:
      start_day += months[month]

    start_day = start_day % 7
    if (start_day == 0):
      count += 1
print count