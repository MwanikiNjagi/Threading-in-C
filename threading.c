#include <stdio.h>
#include <threads.h>

int run(void *arg){
    int *a = arg;

    printf("Thread: Running thread with arg %d\n", *a);

    return 12;
}

int main(void){
   thrd_t t; //will hold the id of the thread
   int arg = 3489;

   printf("Launching a thread\n");

   //launch a thread to the run() function, passing a ponter to 3490
   //as an arg. Also stored the thread ID in t:

   thrd_create(&t, run, &arg);

   printf("Doing other things while the thread runs\n");
   printf("Waiting for the thread to complete...\n");

   int res;//holds return value from the thread exit

   thrd_join(t, &res);
   printf("Thread exited with return value %d\n", res); 

   }
    