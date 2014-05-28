import pdb
word_mappings = {0 : 0,
                 1 : 3,
                 2 : 3,
                 3 : 5,
                 4 : 4,
                 5 : 4,
                 6 : 3,
                 7 : 5,
                 8 : 5,
                 9 : 4,
                 10 : 3,
                 11 : 6,
                 12 : 6,
                 13 : 8,
                 14 : 8,
                 15 : 7,
                 16 : 7,
                 17 : 9,
                 18 : 8,
                 19 : 8,
                 20 : 6,
                 30 : 6,
                 40 : 5,
                 50 : 5,
                 60 : 5,
                 70 : 7,
                 80 : 6,
                 90 : 6,
                }
for i in range(1,10):
  word_mappings[i*100] = word_mappings[i] + 10

word_mappings[1000] = 3 + 8


# We assume that 1 <= numb <= 999
def get_numb_letters(numb):
  (hundreds, tens_and_ones) = divmod(numb, 100)
  if tens_and_ones < 20:
    return word_mappings[hundreds*100] + word_mappings[tens_and_ones]
  else:
    (tens, ones) = divmod(tens_and_ones, 10)
    return word_mappings[hundreds*100] + word_mappings[tens*10] + word_mappings[ones]

print sum(map(get_numb_letters,xrange(1,1000))) + word_mappings[1000]
