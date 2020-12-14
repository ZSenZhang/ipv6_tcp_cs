#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include <arpa/inet.h>

void error(char *msg)
{
    perror(msg);
    exit(1);
}
int main(int argc,char *argv[])
{
    int create_socket,cont;
    struct sockaddr_in6 address;
    if((create_socket=socket(AF_INET6,SOCK_STREAM,0))>0)
    address.sin6_family=AF_INET6;
    address.sin6_port=htons(51870);
    inet_pton(AF_INET6,"2001:48d0:101:501:ec4:7aff:fe69:73e2",&address.sin6_addr);
    if(connect(create_socket,(struct sockaddr*)&address,sizeof(address))<0)
        error("ERROR on binding!\n");
    return close(create_socket);
}

