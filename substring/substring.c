#include <stdlib.h>
#include "substring.h"

/**
 * _strlen - calc the len of string
 * @s: the string
 * Return: the len of the string
 */
static int _strlen(char const *s)
{
	int count = 0;

	while (s[count])
		count++;

	return (count);
}

/**
 * _strncmp - compare 2 string with the len of caracter
 * @a: the first string
 * @b: the second string
 * @n: the length of caracter
 * Return: 1 if equal or return if not the case
 */
static int _strncmp(char const *a, char const *b, int n)
{
	int count = 0;

	while (count < n)
	{
		if (a[count] != b[count])
			return (0);
		count++;
	}
	return (1);
}

/**
 * match - checks if a word exists in array and is unused
 * @s: string position
 * @words: array of words
 * @used: array marking world used words
 * @nw: number of world
 * @n: length of word
 * Return: 1 if the case or 0 otherwise
 */
static int match(char const *s, char const **words, int *used, int nw, int n)
{
	int count = 0;

	while (count < nw)
	{
		if (!used[count] && _strncmp(s, words[count], n))
		{
			used[count] = 1;
			return (1);
		}
		count++;
	}
	return (0);
}

/**
 * check_position - check if all words match at position
 * @s: string position
 * @words: array of words
 * @nb_words: number of words
 * @word_len: word length
 * @used: used array
 * Return: 1 if full match, 0 otherwise
 */
static int check_position(char const *s, char const **words,
	int nb_words, int word_len, int *used)
{
	int j = 0;

	while (j < nb_words)
	{
		if (!match(s + j * word_len, words, used, nb_words, word_len))
			return (0);
		j++;
	}
	return (1);
}

/**
 * find_substring - find all substring indices
 * @s: string we need to scan
 * @words: array of words
 * @nb_words: the number of words
 * @n: output size
 * Return: array of indice or []
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *res, *used;
	int i, start = 0, word_len, total_len, s_len;

	*n = 0;
	if (!s || !words || nb_words == 0)
		return (NULL);

	word_len = _strlen(words[0]);
	total_len = word_len * nb_words;
	s_len = _strlen(s);

	res = malloc(sizeof(int) * s_len);
	if (!res)
		return (NULL);

	while (start <= s_len - total_len)
	{
		used = malloc(sizeof(int) * nb_words);
		if (!used)
		{
			free(res);
			return (NULL);
		}

		i = 0;
		while (i < nb_words)
			used[i++] = 0;

		if (check_position(s + start, words, nb_words, word_len, used))
			res[(*n)++] = start;

		free(used);
		start++;
	}
	if (*n == 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
