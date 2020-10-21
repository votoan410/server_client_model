#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define PORT 8000

int main(int argc, char const *argv[]) 
{ 
 int arr[51];
	
  char buff[1024]= "hello from the server"; 
  int socketfd, addrlen, n;
  socketfd = socket(AF_INET,SOCK_STREAM,0);
  
  struct sockaddr_in addr; //one for server (addr), one for incoming connection(add_c)
  addr.sin_family = AF_INET; //AF_INET --> ipv4
  addr.sin_addr.s_addr = htonl(INADDR_ANY); //will accept connections from any client IP address
  addr.sin_port = htons(PORT); // specify port 
  //htons function makes sure that numbers are stored in memory in network byte order (little endian in this case)
  

  addrlen = sizeof(addr);
  

  //bind(socketfd, addr, addrlenO);
 // bind(socketfd, (struct sockaddr *)&addr, addrlen);
  if ( bind(socketfd, (struct sockaddr *)&addr, addrlen) < 0){
  	printf("error");
  	}
  	
  int backlog = 2;
  //listen(socketfd, backlog);
  if( listen(socketfd, backlog) < 0){
  	printf("error");
  	}
  
   
  	
  struct sockaddr_in add_c;
  int c_len = sizeof(add_c); //address length for the incoming connection
  
  char *hello = "Hello from server";
  
  int flag = 1;
  int size = sizeof(buff);

  while(1){
    //accept(socketfd, (struct sockaddr *)&add_c, &c_len); 
    int confd = accept(socketfd, (struct sockaddr *)&add_c, &c_len);
    if ( confd < 0){
    	printf("errors");
    	}

/*   while(1){
   		read (confd, buff, sizeof(buff)); //read from client
  		// print buffer which contains the client contents 
   		printf("From client: %s \n", buff); 
   }*/
    
    	ssize_t send(socketfd, buff, size,flag);	
  }
  
}

