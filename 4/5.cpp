#include  <stdlib.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#define ITEMS 20
#define POPS 100000
#define BID 1
#define USERS 20
int main(){
  int key;
  int shm_id,shm_id2;
  key=12345;
  srand (time(NULL));
  printf("DUPA");
  shm_id = shmget(key, ITEMS*sizeof(long int), 0666 | IPC_CREAT);
  long int* items = (long int*)shmat(shm_id, NULL, 0);
  shm_id2 = shmget(key+2, sizeof(pthread_mutex_t), 0666 | IPC_CREAT);
  pthread_mutex_t* blokada = (pthread_mutex_t*)shmat(shm_id2, NULL, 0);
  pthread_mutex_init(blokada, NULL);
  if (items == NULL){
      perror("wooopsiee");
        exit(-1);
  }
  for (int i=0;i< ITEMS;i++){
  items[i]=100;
  }
  for (int i=0;i< USERS;i++){
    if (fork() == 0) {
      for (int j=0;j< POPS;j++){
        int item_index =rand() % ITEMS;
        pthread_mutex_lock(blokada);
        items[item_index] = items[item_index] + BID;
        pthread_mutex_unlock(blokada);
      }
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

}
