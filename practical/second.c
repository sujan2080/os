#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	int pid;
	printf("Process related system calls\n");
	if((pid=fork())==-1)
	{
		printf("Error during fork\n");
		exit(0);
	}
	if(pid==0)
	{
		printf("child process");
		printf("process id of child in child=%d\n",getpid());
		printf("process id of parent in child=%d\n",getppid());
		exit(0);
	}
	else
	{
		printf("parent process");
		printf("process id of child in parent=%d\n",getpid());
		printf("process id of parent in parent=%d\n",getppid());
		exit(0);
	}
	return 0;
}

