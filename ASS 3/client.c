#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc, char **argv)
{
    char buff[100];
	int sockfd, connfd;
	struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(22000);

    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    while(1)
    {
        bzero(buff, sizeof(buff));
        printf("Client: ");
        fgets(buff,100,stdin);
        send(sockfd, buff,strlen(buff),0);

        bzero(buff, sizeof(buff));
        recv(sockfd,buff,100,0);
        printf("Server: %s",buff);
    }
    close(sockfd);
}


// #include<sys/socket.h>
// #include<sys/types.h>
// #include<netdb.h>
// #include<stdio.h>
// #include<string.h>
// #include<arpa/inet.h>
// #include<unistd.h>
// #define PORT 22000

// int main(int argc, char **argv)
// {
//     char s[100],r[100];
//     int socket_fd;
//     struct sockaddr_in servaddr;
//     socket_fd= socket(AF_INET,SOCK_STREAM,0);
//     bzero(&servaddr, sizeof(servaddr));

//     servaddr.sin_family=AF_INET;
//     servaddr.sin_port=htons(PORT);
//     servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

//     connect(socket_fd, (struct sockaddr*)&servaddr, sizeof(servaddr));

//     while (1)
//     {
//         bzero(s,100);
//         bzero(r,100);

//         printf("Client: ");
//         fgets(s,100,stdin);
//         send(socket_fd, s,strlen(s),0);

//         recv(socket_fd,r,100,0);
//         printf("Server: %s",r);
//     }
//     close(socket_fd);
// }