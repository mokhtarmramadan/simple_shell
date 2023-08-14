#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<sys/wait.h>

int main(void)
{
	char *buffer;
	int number;
	size_t size;
	char *token[1];
	char *delim;
	pid_t pid;
	
	delim = "\n";
	size = 100;
	buffer = malloc(sizeof(char) * size);
	if (buffer == NULL)
	{
		perror("Failed\n");
		exit(0);
	}
	while(1)
	{
		printf("#cisfun$ ");
		number = getline(&buffer, &size, stdin);
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
				perror("fail:");
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
