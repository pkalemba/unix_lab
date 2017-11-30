#include  <stdlib.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <time.h>
#define ITEMS 20
#define POPS 10000
#define BID 1
int main(){
    int key;
    int shm_id;

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
 for (int i=0;i< POPS;i++){
	 int item_index =rand() % ITEMS;
	 //printf("Item %d=%ld\n",item_index,items[item_index]);
	 items[item_index] = items[item_index] + BID;

 }
 long int sum = 0;
 for (int i=0;i< ITEMS;i++){
	 printf("Item %d=%ld\n",i,items[i]);
	 sum += items[i];
 }
	 printf("SUMA=%ld\n",sum);


}
