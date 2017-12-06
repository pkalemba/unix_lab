#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#define ITEMS 20
#define POPS 10000
#define USERS 20
#define NULL __DARWIN_NULL
int main() {
    int sock;
    socklen_t serv_len, cli_len;
    struct sockaddr_un serv_addrstr, cli_addrstr;
    int msg[2];
    unlink("gniazdko_klienta");
    sock = socket(PF_UNIX, SOCK_DGRAM, 0);
    cli_addrstr.sun_family = AF_UNIX;
    strcpy(cli_addrstr.sun_path, "gniazdko_klienta");
    cli_len = sizeof(cli_addrstr);
    bind(sock, (struct sockaddr *) &cli_addrstr, cli_len);
    serv_addrstr.sun_family = AF_UNIX;
    strcpy(serv_addrstr.sun_path, "gniazdko_serwera");
    serv_len = sizeof(serv_addrstr);
    srand (time(NULL));
     for (int i=0;i< USERS;i++){
       if (fork() == 0) {
         for (int j=0;j< POPS;j++){
           msg[0] = rand() % ITEMS;
           msg[1] = getpid();
           sendto(sock, &msg, 8, 0, (struct sockaddr *) &serv_addrstr, serv_len);
         }
         exit(0);
       }
    }
    for (int i=0;i< USERS;i++){
	     wait(NULL);
     }
}
