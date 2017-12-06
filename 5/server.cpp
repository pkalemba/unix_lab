#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <string.h>
#define ITER 1000
#define  N_TOWAROW 20
#define N_UCZESTNIKOW 20
#define WART_POCZ 100
#define PRZEBITKA 1

int sum_array(long int a[], int num_elements);
void print_array(long int a[], int num_elements);

int main() 
{
	long int przedmiot[N_TOWAROW];
    long int sum, i;
	for (i = 0; i < N_TOWAROW; i++) 
   	{
    	przedmiot[i] = WART_POCZ;
	}
	int sock;
    socklen_t serv_len, cli_len;
	struct sockaddr_un serv_addrstr, cli_addrstr;
	sock = socket(PF_UNIX, SOCK_DGRAM, 0);
	serv_addrstr.sun_family = AF_UNIX;
	strcpy(serv_addrstr.sun_path,"gniazdko_serwera");
	unlink("gniazdko_serwera");
	serv_len = sizeof(serv_addrstr);
	bind(sock,(struct sockaddr *)&serv_addrstr,serv_len);
	for(i=0; i<(ITER*N_UCZESTNIKOW); i++)
	{
		int buf[2];
		cli_len = sizeof(cli_addrstr);
		recvfrom(sock, &buf, 8, 0, (struct sockaddr *) &cli_addrstr, &cli_len);
		przedmiot[buf[0]]+=PRZEBITKA;
		printf("Client [%d] bided for %d\n", buf[1], buf[0]);
	}
	print_array(przedmiot,N_TOWAROW);
	sum = sum_array(przedmiot, N_TOWAROW);
	printf("Total %ld\n", sum);
	return 0;
}


int sum_array(long int a[], int num_elements)
{
	int i, sum=0;
	for (i=0; i<num_elements; i++)
	{
		sum = sum + a[i];
	}
	return(sum);
}

void print_array(long int a[], int num_elements)
{
	int i;
	for(i=0; i<num_elements; i++)
	{
		printf("%d : %ld \n", i+1, a[i]);
	}
	printf("\n");
}
