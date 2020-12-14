#include <string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include <arpa/inet.h>

int main(int argc,char *argv[])
{
    int count = 0;
    int create_socket,new_socket,addrlen,cont,fd;
    char fname[256];
    struct sockaddr_in6 address;
    if((create_socket=socket(AF_INET6,SOCK_STREAM,0))>0)
    printf("the socket was created\n");
    address.sin6_family=AF_INET6;
    address.sin6_addr=in6addr_any;
    address.sin6_port=htons(51870);
    if(bind(create_socket,(struct sockaddr *)&address,sizeof(address))==0)
    printf("binding socket \n");
    listen(create_socket,3);
    char *command;
    while(1)
    {
        addrlen=sizeof(struct sockaddr_in6);
        new_socket=accept(create_socket,(struct sockaddr*)&address,&addrlen);
        if(new_socket>0){
            char *s = NULL;
            s = malloc(INET6_ADDRSTRLEN);
            inet_ntop(AF_INET6, &(address.sin6_addr), s, INET6_ADDRSTRLEN);
            printf("the client %s is connected...\n", s);
            free(s);
        }
    }
    close(new_socket);
    return close(create_socket);
}




