#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
	char *buffer;
	size_t n;
	ssize_t bytes;
	char **token = NULL;
	int idx = 0;
	pid_t child_process;
	int status;


	n = 10;
	buffer = malloc(sizeof(char) * n);

	if ( buffer == NULL)
		return (0);

	printf("myshell$: ");
	
	bytes = getline(&buffer, &n, stdin);
	printf("Stdin: %s", buffer);
	printf("Number of bytes read: %ld\n", bytes);
	printf("\n");

	token = malloc(strlen(buffer));
	if (!token)
	{
		return (-1);
		printf("Error: Could not allocate tokens");
	}


	token[idx] = strtok(buffer, " ");
	while (token[idx])
	{
		idx++;
		token[idx] = strtok(NULL, " ");

	}

	idx = 0;
	while (token[idx])
	{
		printf("token [%d]: %s\n", idx, token[idx]);
		idx++;
	}
	
	printf("\nparent process: %d\n child process: %d\n",getppid(),getpid());
	child_process = fork();
	if (child_process == 0)
	{
		printf("Child process is starting...\n");
		sleep(3);
		printf("Child process is done\n");
	}
	else
	{
		printf("Waiting fo the child process to complete...\n");
		wait(&status);
		printf("Child process terminated with status: %d\n", status);
	}
	return (0);
}




