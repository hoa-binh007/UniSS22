#include <stdio.h>

int main() {
	char guevara[42];
	printf("Bitte ein Tier eingeben> ");

	if (scanf("%41s",guevara)<1){
		printf("Fehler bei scanf!\n");
	}

	printf("Das Tier ist: %s.\n",guevara);
	return 0;
}
	

