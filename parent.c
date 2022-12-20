#include <stdio.h>
#include <unistd.h>
int main(void)
{
	pid_t p_pid;

	p_pid = getppid();
	printf("%d\n", p_pid);
	return (0);
}
