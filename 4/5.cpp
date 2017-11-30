#include  <stdlib.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t items_mutex;
#define ITEMS 20
#define POPS 10000
#define BID 1
#define USERS 20
int main(){
int key;
int shm_id;
pthread_mutex_t * pmutex = NULL;
pthread_mutexattr_t attrmutex;

/* Initialise attribute to mutex. */
pthread_mutexattr_init(&attrmutex);
pthread_mutexattr_setpshared(&attrmutex, PTHREAD_PROCESS_SHARED);

/* Allocate memory to pmutex here. */

/* Initialise mutex. */
pthread_mutex_init(pmutex, &attrmutex);

/* Use the mutex. */

/* Clean up. */


key=12345;
srand (time(NULL));
shm_id = shmget(key, ITEMS*sizeof(long int), 0666 | IPC_CREAT);
long int* items = (long int*)shmat(shm_id, NULL, 0);
if (items == NULL){
    perror("wooopsiee");
	    exit(-1);
}
for (int i=0;i< ITEMS;i++){
 items[i]=100;
 //printf("Item %d=%ld\n",i,items[i]);
 }
 for (int i=0;i< USERS;i++){
   if (fork() == 0) {
     pthread_mutex_lock(&pmutex);	
     for (int j=0;j< POPS;j++){
       int item_index =rand() % ITEMS;
       //printf("Item %d=%ld FORK\n",item_index,items[item_index]);
       items[item_index] = items[item_index] + BID;
     }
     pthread_mutex_unlock(&pmutex);	
       exit(0);
   }
 }
 for (int i=0;i< USERS;i++){
	 wait(NULL);
 }
 long int sum = 0;
 for (int i=0;i< ITEMS;i++){
	 printf("Item %d=%ld\n",i,items[i]);
	 sum += items[i];
 }
	 printf("SUMA=%ld\n",sum);
pthread_mutex_destroy(pmutex);
pthread_mutexattr_destroy(&attrmutex); 

}
