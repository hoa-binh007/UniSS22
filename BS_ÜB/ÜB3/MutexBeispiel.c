#include <pthread.h>
int i = 0;
pthread_mutex_t lock;

main() {
    pthread_mutex_init(&lock, NULL);
	/* erstelle zwei Threads ... */ 
	/* warte auf Beenden ... */ 
	pthread_mutex_destroy(&lock);
}
	f1() { /* Thread 1 */ 
	pthread_mutex_lock(&lock); 
	i++; 
	pthread_mutex_unlock(&lock);
}
	f2() { /* Thread 2 */ 
	pthread_mutex_lock(&lock); 
	i++; 
	pthread_mutex_unlock(&lock);
}
