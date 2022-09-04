#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include<unistd.h>

int main()
{
	int sockfd, connfd;
	struct sockaddr_in servaddr, cli;
    char buff[100];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(22000);

    bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(sockfd, 5);
    connfd = accept(sockfd, (struct sockaddr*)NULL, NULL);

    while(1)
    {
        bzero(buff, 100);
        recv(connfd, buff, 100,0);
        printf("Client: %s",buff);

        bzero(buff, 100);
        printf("Server: ");
        fgets(buff,100,stdin);
        send(connfd, buff,strlen(buff),0); 
    }
    close(sockfd);
}


// #include<sys/types.h>
// #include<sys/socket.h>
// #include<netdb.h>
// #include<stdio.h>
// #include<string.h>
// #include<unistd.h>

// int main()
// {
//     char s[100],r[100];
//     int listen_fd, comm_fd;
//     struct sockaddr_in servaddr;
//     listen_fd= socket(AF_INET, SOCK_STREAM, 0);
//     bzero(&servaddr,sizeof(servaddr));

//     servaddr.sin_family= AF_INET;
//     servaddr.sin_addr.s_addr= htonl(INADDR_ANY);
//     servaddr.sin_port= htons(22000);

//     bind(listen_fd, (struct sockaddr*) &servaddr, sizeof(servaddr));
//     listen(listen_fd,10);

//     while (1)
//     {
//         comm_fd= accept(listen_fd, (struct sockaddr*) NULL, NULL);

//         bzero(s,100);
//         bzero(r,100);

//         recv(comm_fd, r, 100,0);
//         printf("Client: %s",r);

//         printf("Server: ");
//         fgets(s,100,stdin);
//         send(comm_fd, s,strlen(s),0);
//     }
//     close(comm_fd);
// }