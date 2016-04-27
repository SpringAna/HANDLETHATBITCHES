#include <stdio.h>
#include <string.h>
//#include <sys/types.h>
#include "cmdline.h"
//#include <unistd.h> 
#include  <signal.h>
#define BUFLEN 4096

#define YESNO(i) ((i) ? "Y" : "N")
//ex5 pas besoin d'utiliser kill
int main(int argc, char* argv[]) {
	struct line li;
	char buf[BUFLEN];
	//pid_t pid=fork();
	line_init(&li);
	int retour=0;
	for (;;) {
		printf("fish> ");
		fgets(buf, BUFLEN, stdin);

		int err = line_parse(&li, buf, strlen(buf)); //ne pas toucher à line_parse 0 si pas erreurs de commandes
		if (err) {
			line_reset(&li); //supprime les fuites mémoires si erreurs ligne de commande
			return 0; //il faudra mettre un continue plus tard
		}
		if(li.ncmds==0)
		{
			fprintf(stderr,"Command not found!\n");
			retour=-1;
			continue;
		}
		/*if(pid==0)
		{
			execvp(li.cmds[0], li.cmds);
			continue;
		}*/
		printf("Command line:\n"); //affiche les dif champs de la struct line
		printf("\tNumber of commands: %zu\n", li.ncmds);

		size_t i, j;
		for (i = 0; i < li.ncmds; ++i) {
			printf("\t\tCommand #%zu:\n", i);
			printf("\t\t\tNumber of args: %zu\n", li.cmds[i].nargs);
			printf("\t\t\tArgs:");
			for (j = 0; j < li.cmds[i].nargs; ++j) {
				printf(" \"%s\"", li.cmds[i].args[j]);
			}
			printf("\n");
		}

		printf("\tRedirection of input: %s\n", YESNO(li.redirect_input));
		if (li.redirect_input) {
			printf("\t\tFilename: '%s'\n", li.file_input);
		}

		printf("\tRedirection of output: %s\n", YESNO(li.redirect_output));
		if (li.redirect_output) {
			printf("\t\tFilename: '%s'\n", li.file_output);
		}

		printf("\tBackground: %s\n", YESNO(li.background));

		/* do something with li */

		line_reset(&li);
		if(signal(sig, SIG_IGN))
		{
			printf("The process  with errors\n");
		}
		if(retour<0)
		{
			printf("The process ended with errors\n");
		}
		else
		{
			printf("The process ended without errors\n");
		}
	}
}

