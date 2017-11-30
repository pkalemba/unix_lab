#include<stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#define ITEMS 20
#define POPS 10000
#define BID 1
int main(void)
{
 printf("Hello! This is a test prgoram.\n");
 srand (time(NULL));
 long int items[ITEMS];
 for (int i=0;i< ITEMS;i++)
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

 return 0;
}
