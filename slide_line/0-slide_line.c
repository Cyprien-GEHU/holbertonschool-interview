#include "slide_line.h"

/**
 * check - check if we have all info
 * @line: array of interger
 * @size: size of the array
 * @direction: Direction of the slide
 * Return: 0 if not valide and 1 if the case
 */

int check(int *line, size_t size, int direction)
{
	if (line == NULL || size == 0)
		return (0);
	if (direction != SLIDE_RIGHT && direction != SLIDE_LEFT)
		return (0);

	return (1);
}

/**
 * slide_right - fonction to slide to the right
 * @line: array of interger
 * @size: size of the array
 */

void slide_right(int *line, size_t size)
{
	size_t i, j = 0, s = size;
	int tempo[1024] = {0};

	for (i = size; i-- > 0;)
		if (line[i] != 0)
			tempo[j++] = line[i];

	if (j == 0)
		return;

	for (i = 0; i < j - 1; i++)
	{
		if (tempo[i] == tempo[i + 1] && tempo[i])
		{
			tempo[i] *= 2;
			tempo[i + 1] = 0;
		}
	}

	for (i = 0; i < j; i++)
		if (tempo[i] != 0)
			line[--s] = tempo[i];

	while (s-- > 0)
		line[s] = 0;
}

/**
 * slide_left - fonction to slide to the left
 * @line: array of interger
 * @size: size of the array
 */

void slide_left(int *line, size_t size)
{
	size_t i, j;
	int tempo[1024] = {0};

	for (i = 0, j = 0; i < size; i++)
		if (line[i] != 0)
			tempo[j++] = line[i];

	for (i = 0; i < size - 1; i++)
	{
		if (tempo[i] == tempo[i + 1] && tempo[i])
		{
			tempo[i] *= 2;
			tempo[i + 1] = 0;
		}
	}

	for (i = 0, j = 0; i < size; i++)
		if (tempo[i] != 0)
			line[j++] = tempo[i];

	while (j < size)
		line[j++] = 0;
}

/**
 * slide_line - make a slime and marge same value
 * @line: array of interger
 * @size: size of the array
 * @direction: Direction of the slide
 * Return: 1 for succes, o for failure
 */

int slide_line(int *line, size_t size, int direction)
{
	if (!check(line, size, direction))
		return (0);

	if (direction == SLIDE_LEFT)
		slide_left(line, size);

	if (direction == SLIDE_RIGHT)
		slide_right(line, size);

	return (1);
}
