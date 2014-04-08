#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<error.h>
#include<netdb.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<arpa/inet.h>
#include<signal.h>

/*Function to find the address of Client connected with the server*/
void *get_ip_address_client(struct sockaddr *sa){

    if(sa->sa_family == AF_INET){
	   struct sockaddr_in *ipv4 = (struct sockaddr_in*)sa;
	   return &(ipv4->sin_addr);
	}
	else if(sa->sa_family == AF_INET6){
	   struct sockaddr_in6 *ipv6 = (struct sockaddr_in6*)sa;
	   return &(ipv6->sin6_addr);
	}
	
	perror("get_ip_address: Error\n");
	exit(0);
}

/*Function to find the Address of the Server i.e Own host*/
void *get_ip_address(struct addrinfo *sa){

    if(sa->ai_family == AF_INET){
	   struct sockaddr_in *ipv4 = (struct sockaddr_in*)sa->ai_addr;
	   return &(ipv4->sin_addr);
	}
	else if(sa->ai_family == AF_INET6){
	   struct sockaddr_in6 *ipv6 = (struct sockaddr_in6*)sa->ai_addr;
	   return &(ipv6->sin6_addr);
	}
	
	perror("get_ip_address: Error\n");
	return NULL;
}

int main(int argc,char *argv[])
{
   /*Socket Structure declration*/
   struct addrinfo hints,*res,*p;

   //struct sockaddr_storage addrStore;
   int status;
   char ipaddr[INET6_ADDRSTRLEN];
   void *hostip;
   
   
   /*Server Information*/
   //int sockfd;
   
   /*Fill Socket Structure*/
   memset(&hints,0,sizeof(hints));
   hints.ai_family=AF_UNSPEC;
   hints.ai_socktype = SOCK_STREAM;
   //hints.ai_flags = AI_PASSIVE;
   
   if(argc < 2){
    printf("Usages : showIP  <hostname/address>\n");
    return 0;
   }
   /*Get Address info*/
   //if((status = getaddrinfo(NULL,MYPORT,&hints,&res)) !=0){
   if((status = getaddrinfo(argv[1],NULL,&hints,&res)) !=0){
       fprintf(stderr,"getaddrinfo Failed %s :\n",gai_strerror(status));
	   exit(0);
   }
   
   for(p=res;p!=NULL;p=p->ai_next){
      //hostip = get_ip_address_client((struct sockaddr *)p);
      hostip = get_ip_address(p);
	  inet_ntop(p->ai_family,hostip,ipaddr,sizeof(ipaddr));
	  printf("Host ip Address is : %s\n",ipaddr);
	  
   }
   
   
   freeaddrinfo(res);
   return 0;
}


