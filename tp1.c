#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *threadT4(){

printf("Thread T4 de pid %d\n", (int) gettid());
printf("Calcul de A*B \n");
}
void *threadT5(){
printf("Thread T5 de pid %d\n", (int) gettid());
printf("Calcul de C*D \n");
}
void *threadT6(){

printf("Thread T6 de pid %d\n", (int) gettid());
printf("Calcul de A+B \n");
}
void *threadT7(){
printf("Thread T7 de pid %d\n", (int) gettid());
printf("Calcul de C-D \n");
}

void *threadT2(void *threadid){
pthread_t thT4,thT5;
printf("Création du thread T4\n");
pthread_create(&thT4, NULL,&threadT4, NULL);
printf("Création du thread T5\n");
pthread_create(&thT5, NULL,&threadT5, NULL);
pthread_join(thT4, NULL);
pthread_join(thT5, NULL);
}
void *threadT3(void *threadid){
pthread_t thT6,thT7;
printf("Création du thread T6\n");
pthread_create(&thT6, NULL,&threadT6, NULL);
printf("Création du thread T7\n");
pthread_create(&thT7, NULL,&threadT7, NULL);
pthread_join(thT6, NULL);
pthread_join(thT7, NULL);
}


void *threadT1(void *threadid){

pthread_t thT2,thT3;
printf("Création du thread T2 de tid %d\n", (int) gettid());
pthread_create(&thT2, NULL,&threadT2, NULL);
sleep(1);
printf("Création du thread T3 de tid %d\n",(int) gettid());
pthread_create(&thT3, NULL,&threadT3, NULL);
pthread_join(thT2, NULL);
pthread_join(thT3, NULL);
}


int main() 
{
long t;
pthread_t thT1;
printf("Création du thread T1 de tid %d\n", (int) gettid());
pthread_create(&thT1, NULL,&threadT1, (void *)t);
sleep(1);
pthread_join(thT1, NULL);
printf("Calcul de R1/R2\n");
return 0;
}
