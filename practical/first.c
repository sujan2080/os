#include<stdio.h>
#include<unistd.h>

int main()
{
	int pid,ppid;
	pid=getpid();
	printf("\n Process Id is %d\n",pid);
	printf("\n Parent Process Id is %d\n",ppid);
	return 0;
}

