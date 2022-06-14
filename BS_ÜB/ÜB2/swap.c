#include <stdio.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void){
	int olerant = 42, ernational = 4711;
	swap(&olerant, &ernational);

	printf("%d %d\n", olerant, ernational);
	return 0;
}

