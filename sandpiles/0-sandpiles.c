#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * stable_check - check if the grid are unstable
 * @grid: 3x3 grid
 * Return: 0 if stable and 1 is not stable
 */
static int stable_check(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			if (grid[x][y] > 3)
			{
				return (1);
			}
	return (0);
}

/**
 * topple - topple the grid
 * @grid: 3x3 grid
 */
static void topple(int grid[3][3])
{
	int x, y;
	int tmp[3][3];

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			tmp[x][y] = grid[x][y];

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (tmp[x][y] > 3)
			{
				grid[x][y] -= 4;
				if (x - 1 >= 0)
					grid[x - 1][y] += 1;
				if (x + 1 < 3)
					grid[x + 1][y] += 1;
				if (y - 1 >= 0)
					grid[x][y - 1] += 1;
				if (y + 1 < 3)
					grid[x][y + 1] += 1;
			}
		}
	}
}

/**
 * sandpiles_sum - add two sandpile
 * @grid1 : first grid 3x3
 * @grid2: second grid 3x3
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
			grid1[x][y] += grid2[x][y];
	}

	while (stable_check(grid1))
	{
		print_grid(grid1);
		topple(grid1);
	}
}
