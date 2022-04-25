#include <stdio.h> 
#include <stdlib.h>
int fib(int a){
if(a == 0) return 0;
if(a == 1) return 1;
else return fib(a-1)+fib(a-2);
}

int main( int argc,char *argv[]){
int input = atoi(argv[1]);;
if(argc != 2){
printf("Es ist genau ein Argument erforderlich.");
return -1;
}
else {
if(input < 0) {
printf("Negative Zahl als Obergrenze angegeben.");
return -1;
}
else {
printf("Die %d. Fibonacci-Zahl lautet: %d.\n", input , fib(input));
}
}
return 0;
}
