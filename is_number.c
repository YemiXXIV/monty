#include "monty.h"

/**
 * is_number - Checks if a string is a number
 * @str: String to check
 * Return: 1 if the string is a number, 0 otherwise
 */

int is_number(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	if (str[0] == '-')
		i = 1;

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}
