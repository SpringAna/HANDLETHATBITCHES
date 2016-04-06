#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void sig_handler(int sig)
{
	if(sig==SIGINT)
	{
		printf("boom!\n");
	}
}

int main(int argc, char *argv[])
{
	struct sigaction sa;
	sa.sa_handler = sig_handler;
	if (sigaction(SIGKILL, &sa, NULL) != -1) {
		sig_handler(atoi(argv[1]));	
	}
	exit(EXIT_SUCCESS);
}
