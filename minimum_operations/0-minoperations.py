#!/usr/bin/python3
"""
the programme will find the Minimum Operations of a number :
    n: the number
    retunr : 0 or the minimum operations
"""


def minOperations(n):
    num = 0
    factor = 2

    if n < 2:
        return 0

    while n > 1:
        while n % factor != 0:
            factor += 1
        n = n/factor
        num += factor

    return num
