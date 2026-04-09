#include "regex.h"

/**
 * regex_match - check if the given string match with a given pattern
 * @str: given string
 * @pattern: given pattern
 * Return: 1 if match, otherwise is 0
 */
int regex_match(char const *str, char const *pattern)
{
	int first_match;

	if (*pattern == '\0')
		return (*str == '\0');

	first_match = (*str != '\0' && (*pattern == *str || *pattern == '.'));

	if (*(pattern + 1) == '*')
	{
		return (regex_match(str, pattern + 2) ||
		(first_match && regex_match(str + 1, pattern)));
	}
	return (first_match && regex_match(str + 1, pattern + 1));
}
