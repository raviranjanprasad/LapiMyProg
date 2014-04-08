#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<arpa/inet.h>

#define MYPORT "3333"
#define BACKLOG 10

void *get_ip_Address(struct sockaddr *sa){

    if(sa->sa_family == AF_INET){
      struct sockaddr_in *ipv4 = (struct sockaddr_in *)sa;
      return &(ipv4->sin_addr);
    }
    else{
      struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)sa;
      return &(ipv6->sin6_addr);
    }

   perror("get_ip_Address : Failed\n");
   exit(0);
    
}

int main(int argc, char *argv[]){

  /*Socket Structure*/
  struct addrinfo hints,*res,*p;
  int status;
  char ipAddr[INET6_ADDRSTRLEN];


  /*Server Declaration*/
  int sockfd,new_fd;
  struct sockaddr_storage client;
  socklen_t client_len;
  int yes;

  /*Fill Structure*/
  memset(&hints,0,sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if(argc < 2){
    printf("Usages: server <ClientHostname/ClentIP>\n");
    exit(1);
  }
  
  if((status = getaddrinfo(argv[1],MYPORT,&hints,&res)) != 0){
     fprintf(stderr,"getaddrinof Failed %s : \n",gai_strerror(status));
     exit(0);
  }
   
  for(p=res;p!=NULL;p=p->ai_next){

     sockfd = socket(p->ai_family,p->ai_socktype,p->ai_protocol);
     if(sockfd == -1){
        perror("Server: socket() failed\n");
        continue;
     }
    
     if(setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int))== -1){
       perror("Server: setsockopt() failed\n");
       exit(1);
     }

     if(bind(sockfd,p->ai_addr,p->ai_addrlen)== -1){
        close(sockfd);
        perror("Server: bind() failed\n");
        continue;
     }

     break;
  }

  if(p==NULL){
    perror("Server: bind() failed\n");
    exit(1);
  }

  freeaddrinfo(res);

  if(listen(sockfd,BACKLOG)){
    perror("Server : listen() failed\n");
    exit(1);
  }
  
  printf("Server Waiting for Connection...........\n");
  while(1){
  client_len = sizeof(client);
  new_fd=accept(sockfd,(struct sockaddr *)&client,&client_len);
  if(new_fd == -1){
    perror("Server: accept() failed\n");
    continue;
  }

  inet_ntop(client.ss_family,get_ip_Address((struct sockaddr *)&client),ipAddr,sizeof(ipAddr));
  printf("Client Connected %s:\n",ipAddr);

  if(!fork()){
    close(sockfd);  //child doesn't need thissockfd
    if(send(new_fd,"Hello World",13,0) == -1)
     perror("Server : send() failed\n");

    close(new_fd);
    exit(0);
  
  }
  close(new_fd);  //Parent Doesn't need this_sockfd

  }
}
