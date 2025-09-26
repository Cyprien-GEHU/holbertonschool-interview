#!/usr/bin/python3
""" parse logs and return the number of error ans the size of the file"""

import sys

SC = [200, 401, 403, 404, 405, 500]


def read_line(line):
    """extract all data we need form the ligne"""
    text = line.strip().split()
    if not text:
        return None, None

    try:
        size_file = int(text[-1])
    except (ValueError):
        size_file = None

    try:
        status_code = int(text[-2])
    except ValueError:
        status_code = None

    else:
        return None, None

    return status_code, size_file


def stats():
    """the main function"""

    n_line = 0
    code = {}
    total_size = 0

    try:
        for line in sys.stdin:
            n_line += 1
            status_code, size_file = read_line(line)

            if size_file is not None:
                total_size += size_file

            if status_code is not None and status_code in SC:
                code[status_code] = code.get(status_code, 0) + 1

            if n_line % 10 == 0:
                print(f'File size: {total_size}')
                for status in sorted(SC):
                    if status in code:
                        print(f"{status}: {code[status]}")

    except KeyboardInterrupt:
        pass


if __name__ == "__main__":
    stats()
