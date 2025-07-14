#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int flag[2]={0, 0};
int turn =0;

void *process(void *param)
{
	int i=*(int *)param;
	int other = 1-i;

	for(int cnt=0; cnt < 5; cnt++)
	{
		flag[i]=1;
		turn =other;
		while (flag[other] && turn==other)
		{

		}
		printf("Process %d is in the critical section (iteration %d)\n",i,cnt+1);
		sleep(1);
		flag[i]=0;
		printf("Process %d is in the remainder section\n",i);
		sleep(1);
	}
	return NULL;
}

int main()
{
	pthread_t t1,t2;
	int id1=0, id2=1;
	pthread_create(&t1,NULL,process,&id1);
	pthread_create(&t2,NULL,process,&id2);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("Both processes have finished.\n");
	return 0;

}
