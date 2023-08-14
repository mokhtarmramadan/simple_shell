#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<sys/wait.h>

int check_space(char *buff);

/**
 * main - Entry point
 * Return: 0 (success)
 **/
int main(void)
{
	char *buffer, *token[1], *delim;
	int number;
	size_t size = 100;
	pid_t pid;

	delim = " \n";
	buffer = malloc(sizeof(char) * size);
	if (buffer == NULL)
	{
		perror(NULL);
		exit(0);
	}
	while (1)
	{
		if (isatty(0) == 1)
			printf("#cisfun$ ");
		number = getline(&buffer, &size, stdin);
		if (check_space(buffer) == 0)
		{
			if (buffer != NULL)
			{
				free(buffer);
			}
			continue;
		}
		if (number == EOF || number == -1)
		{
			free(buffer);
			write(0, "\n", 2);
			exit(0);
		}
		token[0] = strtok(buffer, delim);
		token[1] = NULL;

		pid = fork();
		if (pid == 0)
		{
			number = execve(token[0], token, NULL);
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

int check_space(char *buff)
{
        int i;

        for (i = 0; i < strlen(buff) - 1; i++)
        {
                if (buff[i] == ' ')
                {
                        continue;
                }
                else
                {
                        return (1);
                }
        }
        return (0);
}
