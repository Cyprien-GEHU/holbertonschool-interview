#!/usr/bin/python3
import sys


def safe(row, col, solution):
    """see if the queen is safe"""
    for r, c in solution:
        if c == col or abs(row - r) == abs(col - c):
            return False
    return True


def possibilty(N, row, solution, solutions):
    """function to see all possibility of solution"""
    if row == N:
        solutions.append(list(solution))
        return
    for col in range(N):
        if safe(row, col, solution):
            solution.append([row, col])
            possibilty(N, row + 1, solution, solutions)
            solution.pop()


def main():
    """the main function"""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = []
    possibilty(N, 0, [], solutions)
    for result in solutions:
        print(result)


if __name__ == "__main__":
    main()
