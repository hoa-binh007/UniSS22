#include <stdlib.h>
#include <stdio.h>
#define P() ({ int status = sem_wait(&((*rezept[i]).sem)); if(status) {printf("Fehler\n"); exit(-1); } else { printf("[BT%d] %d-te Zutat aus Rezept holen.\n", my_num, i); }})
#define V() ({ int status = sem_post(&((*rezept[i]).sem)); if(status) {printf("Fehler\n"); exit(-1); } else { printf("[BT%d] %d-te Zutat aus Rezept wegstellen.\n", my_num, i); }})
#define LOCK() ({ int status = pthread_mutex_lock(&lock); if(status) {printf("Fehler\n"); exit(-1); } else { printf("[BT%d] Regal sperren.\n", my_num); }})
#define UNLOCK() ({ int status = pthread_mutex_unlock(&lock); if(status) {printf("Fehler\n"); exit(-1); } else { printf("[BT%d] Regal freigegeben.\n", my_num); }})
#define DRINKMISCHEN() (sleep(rezept[i] -> time_needed))

#include "vorgabe.h"

void *work(void *arg){
	int my_num = *((int *)arg);

	printf("[BT%d] Ich bin bereit zu arbeiten!\n", my_num);

	for ( int n = 0; n<RECIPES_PER_BARTENDER; n++) {
		
		//Rezept generieren
		ingredient_t* rezept[RECIPE_SIZE];  // Zeiger rezept der Funktion getR übergeben
		get_recipe(rezept);
		
		LOCK();
		
		//eine Spirittuose aus dem Regal holen also semaphore ausführen
		for(int i=0; i<RECIPE_SIZE;i++){
			P();
		}
		
		UNLOCK();
		
		for(int i=0; i<RECIPE_SIZE;i++){
			DRINKMISCHEN();
		}
		
		//Alle Zutaten ins Regal stellen
		for(int i=0; i<RECIPE_SIZE;i++){
			V();
		}
	
		printf("[BT%d] Drink fertig!\n", my_num);
	}
	
	printf("[BT%d] Alle Drinks sind fertig \n", my_num);

	pthread_exit(NULL);
	
	return NULL;
}

