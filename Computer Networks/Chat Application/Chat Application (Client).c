#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

void * doRecieving(void * sockID)
{

	int clientSocket = *((int *) sockID);

	while(1)
	{
		char data[1024];
		int read = recv(clientSocket,data,1024,0);
		data[read] = '\0';
		printf("%s\n",data);
	}

}

int main()
{
	int clientNo,clientSocket;
	if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("Couldn't create socket\n");
		return -1;
	}

	struct sockaddr_in serverAddr;

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(8080);
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(connect(clientSocket, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) == -1) 
	{
		printf("Couldn't connect to client\n");
		return -1;
	}
	
	printf("Connection established to server.\n");
	printf("\nEnter command LIST to list out all available clients OR\nSEND to send a message to a particular client.\n\n");

	pthread_t recieveThread;
	pthread_create(&recieveThread, NULL, doRecieving, (void*)&clientSocket);
	
	while(1)
	{
		char input[1024];
		scanf("%s",input);

		if(strcmp(input,"LIST") == 0)
		{
			send(clientSocket,input,1024,0);
		}
		if(strcmp(input,"SEND") == 0)
		{		
			send(clientSocket,input,1024,0);
			
			printf("Enter client number to send message : ");
			scanf("%d",&clientNo);
			clientNo = htonl(clientNo);
			send(clientSocket,&clientNo,sizeof(clientNo),0);
			
			printf("Enter message : ");
			scanf(" %[^\n]s",input);
			send(clientSocket,input,1024,0);
		}

	}

	pthread_join(recieveThread,NULL);
	return 0;
}
