#!/usr/bin/python3
"""
Utf-8 validation
"""


def validUTF8(data):
    """ the main function """
    nBytes = 0

    for nb in data:
        
        if nb < 0 or nb > 255:
            return False
        
        b = format(nb, "08b")

        if nBytes == 0:
            if b.startswith('0'):
                continue
            elif b.startswith('110'):
                nBytes = 1
            elif b.startswith('1110'):
                nBytes = 2
            elif b.startswith('11110'):
                nBytes = 3
            else:
                return False
        else:
            if not b.startswith('10'):
                return False
            
            nBytes -= 1

    return nBytes == 0
