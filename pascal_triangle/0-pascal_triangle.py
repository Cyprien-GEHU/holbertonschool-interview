#!/usr/bin/python3
"""
The programme do a pascal triangle
"""


def pascal_triangle(n):
    """ return a liste of pascal triangle"""

    if n <= 0:
        return []

    tri = []
    i = 0

    while i < n:
        row = [1] * (i + 1)
        j = 1

        while j < i:
            row[j] = tri[i - 1][j - 1] + tri[i - 1][j]
            j += 1

        tri.append(row)
        i += 1

    return tri
