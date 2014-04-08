#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>

void showIPAddr(char *hostname)
{
    /*Address Structure*/
    struct addrinfo hints,*res,*p;
    int status, port;
    char ipaddr[INET6_ADDRSTRLEN];

    /*Address Collection*/
    void *addr;
    char *addr_type;

    memset(&hints,0,sizeof(hints));
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_family = AF_UNSPEC;

    printf("The hostname passed is %s\n",hostname);
    status=getaddrinfo(hostname,NULL,&hints,&res);
    if(status){
       fprintf(stderr,"getaddrinfo Error:%s\n",gai_strerror(status));
       exit(1) ;
    }
 
    for(p=res;p!=NULL;p=p->ai_next){
        
        if(p->ai_family == AF_INET){
           struct sockaddr_in *ipv4 = (struct sockaddr_in*)p->ai_addr;
           addr = &(ipv4->sin_addr);
           port = ipv4->sin_port;
           addr_type = "IPV4 -Address";
        }
        else if(p->ai_family == AF_INET6){
          struct sockaddr_in6 *ipv6 = (struct sockaddr_in6*)p->ai_addr;
          addr = &(ipv6->sin6_addr);
          port = ipv6->sin6_port;
          addr_type = "IPV6 -Address";
        }
    

    inet_ntop(p->ai_family,addr,ipaddr,sizeof(ipaddr));
    printf("Address Type: %s IP Address: %s Port: %d\n",addr_type,ipaddr,port);
    
   }

   freeaddrinfo(res);
}

int main(int argc,char *argv[])
{
  showIPAddr(argv[1]);  
  return 0;
}
