#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Recommended max cache and object sizes */
#define MAX_CACHE_SIZE 1049000
#define MAX_OBJECT_SIZE 102400
#define BUF_SIZE 500
#define MYPORT 23298  //personal port given by ./port-for-user

/* You won't lose style points for including this long line in your code */
static const char *user_agent_hdr = "User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:10.0.3) Gecko/20120305 Firefox/10.0.3\r\n";

int main(int argc, char *argv[])
{
    printf("%s", user_agent_hdr);

    //set up a TCP socket    
    struct sockaddr_in ip4addr;
    int sfd; 
  	ssize_t nread;
	char buf[BUF_SIZE];


    printf("made it here");


    ip4addr.sin_family = AF_INET;
    ip4addr.sin_port = htons(atoi(argv[1]));
    ip4addr.sin_addr.s_addr = INADDR_ANY;

    if ((sfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket error");
    exit(EXIT_FAILURE);
    }

    if (bind(sfd, (struct sockaddr *)&ip4addr, sizeof(struct sockaddr_in)) < 0) {
    close(sfd);
    perror("bind error");
    exit(EXIT_FAILURE);
    }

    if (listen(sfd, 100) < 0) {
    close(sfd);
    perror("listen error");
    exit(EXIT_FAILURE);
    }

    printf("waiting for connection");

    while(1) {
		sfd = accept(sfd, NULL, NULL);
	}










    printf("stopping server");
    return 0;
}
