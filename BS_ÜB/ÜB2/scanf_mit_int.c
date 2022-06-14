#include <stdio.h>

int main() {
	int eastwood;
    printf("Bitte eine ganze Zahl eingeben> ");

	if (scanf("%d",&eastwood)<1) { 
	printf("Fehler bei scanf!\n");
	return 1; 
	}
    printf("Die Zahl ist %d.\n",eastwood);
	return 0; 
	}

