#include "menger.h"


/**
 * draw - the function to see we draw or not
 * @line: row position
 * @colm: column position
 * Return: 1 if we have hole or 0 otherwise
 */

int draw(int line, int colm)
{
	while (line > 0 || colm > 0)
	{
		if (line % 3 == 1 && colm % 3 == 1)
			return (1);

		line /= 3;
		colm /= 3;
	}
	return (0);
}


/**
 * menger - main function to generte a menger sponge
 * @level: the level of the menger
 */

void menger(int level)
{
	int sponge_size, line, colm;

	if (level < 0)
		return;

	sponge_size = pow(3, level);

	for (line = 0; line < sponge_size; line++)
	{
		for (colm = 0; colm < sponge_size; colm++)
		{
			if (draw(line, colm))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
