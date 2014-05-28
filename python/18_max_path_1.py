import pdb

def read_grid(filename):
  f = open(filename)
  grid = []
  for line in f.readlines():
    grid.append(map(int, line.split(' ')))

  return grid

grid = read_grid('../data/18_max_path_1.txt')
max_grid = []

#pdb.set_trace()
for i in range(15):
  grid_level = []
  for j in range(i+1):
    elem = grid[i][j]
    try:
      above = max_grid[i-1][j]
    except:
      above = 0

    try:
      above_left = max_grid[i-1][j-1]
    except:
      above_left = 0

    grid_level.append(elem + max(above, above_left))
  max_grid.append(grid_level)
#print grid
print max(max_grid[-1])