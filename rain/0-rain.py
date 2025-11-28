#!/usr/bin/python3
""" rainwater program"""


def rain(walls):
    """function rain and return the number of rainwater we can stock """
    if len(walls) < 3 and not walls:
        return 0

    size_wall = len(walls)
    max_right = [0] * size_wall
    max_left = [0] * size_wall

    max_left[0] = walls[0]
    for index in range(1, size_wall):
        max_left[index] = max(max_left[index - 1], walls[index])

    max_right[size_wall - 1] = walls[size_wall - 1]
    for index in range(size_wall - 2, -1, -1):
        max_right[index] = max(max_right[index + 1], walls[index])

    rainwater = 0

    for index in range(size_wall):
        stock = min(max_left[index], max_right[index]) - walls[index]
        if stock > 0:
            rainwater += stock
    return rainwater
