#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	printf("Before Forking, PID: %d\n", getpid());
	int pid1 = fork();

	/* Child1 Process. */
	if(pid1 == 0)
	{
		printf("Hey! I'm Child1 with PID: %d, My Parent PID: %d\n", getpid(), getppid());
		int i = 0;
		while(i>=0)
		{
			/* prints every 1 second */
			printf("PID at %dth second is: %d\n", i, getpid());
			i++;
			sleep(1);
		}
	}
	/* parent process */
	else
	{
		printf("In Parent Process with PID: %d before forking child2.\n", getpid());
		int pid2 = fork();
		/* Child2 Process */
		if(pid2 == 0)
		{
			printf("Hey! I'm Child2, My PID: %d, My Parent PID: %d, I'm going to sleep for 10 seconds now.\n", getpid(), getppid());
			/* Sleeps for 10 seconds */
			sleep(10);
			printf("I'm back after sleeping for 10 seconds! My PID: %d, My Parent PID: %d\nI'm going to kill the Child1 now!\n", getpid(), getppid());
			/* Kills child1 */
			kill(pid1, SIGKILL);
			printf("I have killed Child1. My PID: %d, My Parent PID: %d\nI'm again going to sleep for 10 seconds now,\n", getpid(), getppid());
			/* Sleeps for 10 seconds */
			sleep(10);
			printf("I'm back again after sleeping for 10 seconds. My PID: %d, My Parent PID: %d\nI'm terminating now! Bye.\n", getpid(), getppid());
			/* terminates */
			exit(0);
		}
		/* Parent process */
		else
		{
			printf("In Parent Process with PID: %d after forking child2.\nGoing to wait for Child2 to finish now.\n", getpid());
			/* Waits for the child2 to finish */
			waitpid(pid2, NULL, 0);
			printf("Child 2 finished, back in parent process with PID: %d\n", getpid());
		}
	}
	return 0;
}
			
			
			
			
 	

