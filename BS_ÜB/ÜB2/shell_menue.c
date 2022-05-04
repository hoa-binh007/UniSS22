#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <sys/wait.h>
#include <sys/types.h> /*fuer pid_t benoetigt*/

int main() {
	pid_t pid;
	int x;
	char c;
	int erfolg;
	char const* argument;
	char* befehl = "ls";
	char* text[4] = {"-l", "-a", "-t", "exit"};
	
	while (1) {
		x = 0;
		printf("1. -l\n2. -a\n3. -t\n4. exit\nAuswahl: ");
		if (scanf("%d",&x)<1) { 
			printf("Fehler bei scanf!\n");
			return 1;
		} else if (x > 4 || x < 1) {
			printf("Eintrag %d nicht vorhanden.\n", x);
			return 1;
		} else if (x == 4) {
			printf("Es wurde exit gewählt.\n");	
			break;
		} else {
			printf("Es wurde %s gewählt.\n", text[x-1]);
			argument = text[x-1];
			pid = fork();
			switch (pid) {
				case -1: printf("Fehler bei dem Aufruf von fork().\n"); return 1;
				case 0: execlp(befehl, befehl, argument, 0); return 0;
				default: wait(&erfolg); printf("PID von pwd: %d\n", pid); break;
			}
		}
		
		while((c=getchar()) != '\n' && c != EOF);  //wartet auf Enter oder Strg+D    manuel Befehl fflushs
	}

	return 0; 
	
}
