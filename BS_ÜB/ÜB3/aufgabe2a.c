#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int ANZ_GAESTE = 64;
int ANZ_SERVICEK = 15;
int ANZ_UMRUEHREN = 5;
int TROEDEL_DAUER = 100000;

/// Verbraucht ein bisschen Zeit
void troedeln() {
	        for (int i = 0; i < TROEDEL_DAUER; ++i) {}
}

/// Kocht für den gegebenen Gast.
void kochen(int gast) {
	printf("Koche fuer Gast: ");
	for (int i = 0; i < ANZ_UMRUEHREN; ++i) {
		printf("%4d ", gast); // Beispiel 0015  auf vier Asci Zeichen umgefüllt
	}
	printf("\nSuppe fertig!\n");
}

/// Auftragsbeschreibung für einen Servicekraft struct sind ähnlich wie 
struct zu_bedienen {
	int erster_gast;
	int bis_gast;
};

/// Auftragsbeschreibung für Servicekraft mit Nummer `servicek` erstellen.
struct zu_bedienen bedienliste_fuer(int servicek) {
	int todo = (ANZ_GAESTE / ANZ_SERVICEK);
	struct zu_bedienen result;
	result.erster_gast = servicek * todo;
	result.bis_gast = servicek * todo + todo;
	if (servicek == ANZ_SERVICEK - 1) {
		result.bis_gast = ANZ_GAESTE;
	}
	return result;
}

/// Routine für einen Servicekraft
void *bedienen(void *arg) {
	troedeln();
	struct zu_bedienen *gaeste = (struct zu_bedienen*)(arg);  //pointer zeigt auf Array liste die ich als Servicekraft abarbeiten muss
	for (int i = gaeste->erster_gast; i < gaeste->bis_gast; ++i) {
		kochen(i);
	}
	pthread_exit(NULL);
}


int main(int argc, char *argv[]) {
	//für alle 
	pthread_t threads[ANZ_SERVICEK];
	struct zu_bedienen list[ANZ_SERVICEK];  //Deklariert
	int status;

	for(int i=0; i<ANZ_SERVICEK;i++){
		list[i] = bedienliste_fuer(i);
		status = pthread_create(&threads[i],NULL,&bedienen,&list[i]);
		if (status){
			printf ("Fehler\n");
			return -1;
		}
	}

	for(int i=0; i<ANZ_SERVICEK;i++){
		status = pthread_join(threads[i],NULL);
		if (status){
			printf ("Fehler\n");
			return -1;
		}
	}

	
		

	return EXIT_SUCCESS;
}


