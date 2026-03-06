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
    for x in range(len(grid)):
        for y in range(len(grid[x])):
            if grid[x][y] == 1:
                if grid[x - 1][y] == 0:
                    count += 1
                if grid[x][y - 1] == 0:
                    count += 1
                if grid[x][y + 1] == 0:
                    count += 1 
                if grid[x + 1][y] == 0:
                    count += 1
    return count