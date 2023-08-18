#include "main.h"

/**
 * check_getline - runs some important checks on the buffer
 * @number: number of characters read
 * @buffer: the char stirng we want to check
 * @env: the environment variables char array
 * Return: 0 to exit 1,2 to continue -1 to break
 **/
int check_getline(int number, char *buffer, char **env)
{
	if (number == EOF || number == -1)
	{
		free(buffer);
		write(0, "\n", 2);
		return (0);
	}

	if (strcmp(buffer, "exit\n") == 0)
	{
		return (0);
	}
	else if (strcmp(buffer, "env\n") == 0)
	{
		print_env(env);
		free(buffer);
		return (1);
	}
	else if (check_space(buffer) == 0)
	{
		return (2);
	}
	return (-1);
}
