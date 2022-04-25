#include <stdio.h>

long int globalLI = 48;
char globalC = 'b';
float globalF = 1.2345;
int globalI;
double globalD;


int fib (int n) {
     if ((n == 1) || (n ==2)) return 1;
        else return fib(n-1)+fib(n-2);
}
    
int main (void) {
    short int localSI;
    char localC = 't';
    int localI = 1337;
    
    int x = 9;
    printf ("Die %d. Fibonacci-Zahl lautet: %d.\n", x, fib(x));

printf("Adresse von globalLI ist %p\n" , (void*)&globalLI);
printf("Adresse von globalC ist %p\n" , (void*)&globalC);
printf("Adresse von globalF ist %p\n" , (void*)&globalF);
printf("Adresse von globalI ist %p\n" , (void*)&globalI);
printf("Adresse von globalD ist %p\n" , (void*)&globalD);
printf("Adresse von localSI ist %p\n" , (void*)&localSI);
printf("Adresse von localC ist %p\n" , (void*)&localC);
printf("Adresse von localI ist %p\n" , (void*)&localI);
}
    
