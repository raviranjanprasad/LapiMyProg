#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>

void countNetInterface()
{
    /*Address Structure*/
    struct addrinfo hints,*res,*p;
    int status;
    static int count;


    memset(&hints,0,sizeof(hints));
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_family = AF_UNSPEC;

    status=getaddrinfo(NULL,"3480",&hints,&res);
    if(status){
       fprintf(stderr,"getaddrinfo Error:%s\n",gai_strerror(status));
       exit(1) ;
    }
 
    for(p=res;p!=NULL;p=p->ai_next){ 
        count++;
    
   }
   printf("The no of Network interfaces of this host is %d\n",count);
   freeaddrinfo(res);
}

int main(int argc,char *argv[])
{
  countNetInterface();  
  return 0;
}
