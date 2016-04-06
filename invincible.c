#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void sighandler(int sig)
{
	if(sig==SIGINT)
	{
		printf("boom!\n");
	}
}

int main(int argc, char *argv[])
{
	struct sigaction sa;
	sigaction(SIGINT, &sa, sighandler);
	exit(EXIT_SUCCESS);
}
