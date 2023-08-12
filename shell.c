#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"

int main(void)
{
	char *buffer;
	int number;
	size_t size;
	char *token[1];
	char *delim;
	pid_t pid;
	
	delim = " ";
	size = 100;
	buffer = malloc(sizeof(char) * size);
	if (buffer == NULL)
	{
		perror("Failed\n");
		exit(0);
	}
	while (1)
	{
		pid = fork();
		if (pid == 0)
		{
			number = 0;
			printf("#cisfun$ ");
			number = getline(&buffer, &size, stdin);
			if (number == -1)
			{
				free (buffer);
				_exit (0);
			}
			token[0] = strtok(buffer, delim);
			token[1] = NULL;
			message(execve(token[0], token, NULL));
		}
		else
		{
			wait(NULL);
		}
	}
	free(buffer);
	return (0);
}

