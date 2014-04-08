/*Address Info Structure*/
//First Faishon Show Presented At *Agra Club Night
struct addrinfo{
  int ai_flags;  //AI_PASSIVE,AI_CANONNAME
  int ai_family; //AF_INET,AF_INTE6,AF_UNSPEC
  int ai_socketype;//SOCK_DGRAM,SOCK_STREAM
  int ai_protocol;//0-ANY,1-TCP,2-UPD
  size_t ai_addrlen;//Socket Address Length
  struct sockaddr *ai_addr; //sockaddr_in4, sockaddr_in6
  char *ai_canonname;  //cannon host name
  addrinfo *next;
};

/*Struct sockaddr are deal with two sepereate IPV4 and IPV6 structures,
  When we need IPV4 sockaddr we use sockaddr_in and the typecast it to
  sockaddr and vice versa, same for IPV6 (sockaddr_in6) kind of socket
  structure.*/

struct sockaddr{
  usingned short sa_family;
  char sa_data[14];
};


