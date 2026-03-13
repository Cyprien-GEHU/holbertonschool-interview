#!/usr/bin/python3
"""
the function for found the perimeter of the island on grid
"""

def island_perimeter(grid):
    """
    function islande perimeter:
    - grid : the representation of island
    return the perimeter of island
    """
    count = 0
    row = len(grid)
    col = len(grid[0])
    for x in range(row):
        for y in range(col):
            if grid[x][y] == 1:
                # top
                if  x == 0 or grid[x - 1][y] == 0:
                    count += 1
                #left
                if  y == 0 or grid[x][y - 1] == 0:
                    count += 1
                #right
                if y == col - 1 or grid[x][y + 1] == 0:
                    count += 1
                #bottom
                if x == row -  1 or grid[x + 1][y] == 0:
                    count += 1
    return count