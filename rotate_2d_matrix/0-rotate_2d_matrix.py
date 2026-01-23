#!/usr/bin/python3
"""
rotate_2d_matrix  - Rotation 90 degreese clockwies of 2D matrix
"""


def rotate_2d_matrix(matrix):
    """the fucntion rotation"""
    invert_matrix = matrix[::-1]
    rotation = zip(*invert_matrix)
    matrix[:] = [list(row) for row in rotation]
