#!/usr/bin/python3
import sys
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
total_size = 0
count = 0

try:
    for line in sys.stdin:
        parts = line.split()
        if len(parts) < 9:
            continue
        try:
            code = int(parts[-2])
            size = int(parts[-1])
            total_size += size
            if code in status_codes:
                status_codes[code] += 1
        except Exception:
            continue

        count += 1
        if count % 10 == 0:
            print("File size: {}".format(total_size))
            for code in sorted(status_codes):
                if status_codes[code]:
                    print("{}: {}".format(code, status_codes[code]))
except KeyboardInterrupt:
    pass
finally:
    print("File size: {}".format(total_size))
    for code in sorted(status_codes):
        if status_codes[code]:
            print("{}: {}".format(code, status_codes[code]))
