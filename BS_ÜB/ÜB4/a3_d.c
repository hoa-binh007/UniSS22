#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define RESET() ({ for (int h = 0; h < BARTENDER_NUM) { if (h != mynum) { pthread_cancel(&bartenders[h]); } } })
#define P() ({ int status = sem_timedwait(&((*rezept[i]).sem), &waittime); if(status) {printf("Reset\n"); RESET(); pthread_exit(NULL); } else { printf("[BT %d] %d-te Zutat aus Rezept holen.\n", my_num, i); }})
#define V() ({ int status = sem_post(&((*rezept[i]).sem)); if(status) {printf("Fehler\n"); exit(-1); } else { printf("[BT %d] %d-te Zutat aus Rezept wegstellen.\n", my_num, i); }})
#define DRINKMISCHEN() (sleep(rezept[i] -> time_needed))

#include "vorgabe.h"

void *work(void *arg){
	int my_num = *((int *)arg);

	printf("[BT %d] Ich bin bereit zu arbeiten!\n", my_num);
	
	int max = 0;
	
	for ( int n = 0; n<RECIPES_PER_BARTENDER; n++) {
		
		//Rezept generieren
		ingredient_t* rezept[RECIPE_SIZE];  // Zeiger rezept der Funktion getR übergeben
		get_recipe(rezept);
		
		//eine Spirittuose aus dem Regal holen also semaphore ausführen
		for(int i=0; i<RECIPE_SIZE;i++){
			
			for(int j=0; j<INGREDIENTS_NUM;j++){
				if(ingredients[j] > max){
					max = ingredients[i];
					timemax = max*RECIPE_SIZE;
			}

			struct timespec waittime;
			
			waittime.tv_sec = timemax;
			
			P();
			
			DRINKMISCHEN();
		}
		
		//Alle Zutaten ins Regal stellen
		for(int i=0; i<RECIPE_SIZE;i++){
			V();
		}
	
		printf("[BT %d] Drink fertig!\n", my_num);
	}
	
	printf("[BT %d] Alle Drinks sind fertig \n", my_num);

	pthread_exit(NULL);
	
	return NULL;
}

