#include <stdio.h>
#include <stdlib.h>
/// Zusätzliche Header-Dateien hier!

#include "vorgabe.h"


void init_semaphores() {
	int status =0;

	for(int i = 0; i < INGREDIENTS_NUM; i++) {
		status = sem_init(&ingredients[i].sem, 0, ingredients[i].bottles);
		if(status){
			printf("Fehler\n");
			exit(-1);  //return -1 nur in der Main Methode und  exit (-1) springt in die Main 
		}
	}


}

void destroy_semaphores() {
	int status =0;

	for(int i = 0; i < INGREDIENTS_NUM; i++) {
		status = sem_destroy(&ingredients[i].sem);
		if(status){
			printf("Fehler\n");
			exit(-1);  //return -1 nur in der Main Methode und  exit (-1) springt in die Main 
		}
	}

}

