#include "main.h"

/**
 * main - Entry point
 * Return: 0 (success)
 **/
int main(void)
{
	char *arg[10], *buffer, *delim, *token;
	int number, i;
	size_t size = 100;
	pid_t pid;

	delim = " \n";
	buffer = NULL;
	while (1)
	{
		if (isatty(0) == 1)
			printf("#cisfun$ ");
		number = getline(&buffer, &size, stdin);
		if (number == EOF || number == -1)
		{
			free(buffer);
			write(0, "\n", 2);
			exit(0);
		}
		if (strcmp(buffer, "exit\n") == 0)
		{
			_exit(0);
		}
		if (check_space(buffer) == 0)
		{
			continue;
 		}

		token = strtok(buffer, delim);
		arg[0] = token;
		if (arg[0] == NULL)
		{
			free(buffer);
			exit(0);
		}
		i = 1;
		while (token != NULL)
		{
			token = strtok(NULL, delim);
			arg[i] = token;
			i++;
		}
		if (access(arg[0], F_OK)  == 0)
		{
			pid = fork();
		}

		if (pid == 0)
		{
			number = execve(arg[0], arg, NULL);
			if (number == -1)
			{
				free(buffer);
				perror("./shell");
				exit(0);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	free(buffer);
	return (0);
}

