#include <pthread.h>
#include <stdio.h>

void* Hello(void *arg) {
    printf("Hello! It's me, thread!”);
	pthread_exit(NULL); // oder: return NULL; 
}

int main(void) {
    int status;
	pthread_t thread;

	status = pthread_create(&thread, NULL, &Hello, NULL);
	if (status) { /*Fehlerbehandlung*/ } 
	status = pthread_join(thread, NULL);
	if (status) { /*Fehlerbehandlung*/ }

	pthread_exit(NULL); // Da wegen pthread_join() nur noch 
						// ein Thread läuft, genügt return 0;
}
