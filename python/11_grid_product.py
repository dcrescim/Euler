import os

def get_neighbor_list(i,j):
  neighbors = []
  neighbors.append([[i, j],[i+1, j],[i+2,j], [i+3,j]]) # South
  neighbors.append([[i, j],[i-1, j],[i-2,j], [i-3,j]]) # North
  neighbors.append([[i, j],[i, j+1],[i,j+2], [i,j+3]]) # West
  neighbors.append([[i, j],[i, j-1],[i,j-2], [i,j-3]]) # East
  neighbors.append([[i, j],[i+1, j+1],[i+2,j+2], [i+3,j+3]]) # Southwest
  neighbors.append([[i, j],[i-1, j-1],[i-2,j-2], [i-3,j-3]]) # Northeast
  neighbors.append([[i, j],[i+1, j-1],[i+2,j-2], [i+3,j-3]]) # Southeast
  neighbors.append([[i, j],[i-1, j+1],[i-2,j+2], [i-3,j+3]]) # Northwest

  return neighbors

def check_grid(grid, neighbor_list):

  total = 1  
  for (i,j) in neighbor_list:
    if ((i < 0) or (i >= 20) or (j < 0) or (j >= 20)):
      return 0
    else:
      total *= grid[i][j]
  return total

def grab_grid(filename):
  f = open(filename)
  grid = []
  for line in f.readlines():
    line_numbs = map(int, line.split())
    grid.append(line_numbs)
  return grid


grid = grab_grid('../data/11_grid_product.txt')

max_product = 0
for i in range(20):
  for j in range(20):
    neighbor_list = get_neighbor_list(i,j)
    for elem in neighbor_list:
      max_product = max(max_product, check_grid(grid, elem))

print max_product





