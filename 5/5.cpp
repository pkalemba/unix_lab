#include  <stdlib.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#define ITEMS 20
#define POPS 10000
#define BID 1
#define USERS 20
int main(){
    int server = socket(PF_INET,SOCK_STREAM,0);
    if (server < 0) {
        perror("socket");
        exit(-1);
    }
      // connect to server
    if (connect(server,(const struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) {
        perror("connect");
        exit(-1);
    }
    srand (time(NULL));
     for (int i=0;i< USERS;i++){
       if (fork() == 0) {
         for (int j=0;j< POPS;j++){
           int item_index =rand() % ITEMS;
           char buffer[50];
           int msg;
           msg =sprintf (buffer, "%d %d",item_index,BID)
           send(server, item.c_str(), line.length(), 0);
           items[item_index] = items[item_index] + BID;
         }
         exit(0);
       }
    }
    for (int i=0;i< USERS;i++){
	     wait(NULL);
     }
}
