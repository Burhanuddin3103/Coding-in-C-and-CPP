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

int clientCount = 0;

struct client
{
	int index;
	int sockID;
	struct sockaddr_in clientAddr;
	int len;
} Client[1024];

pthread_t thread[1024];

void * doNetworking(void * ClientDetail)
{

	struct client* clientDetail = (struct client*) ClientDetail;
	int index = clientDetail -> index;
	int clientSocket = clientDetail -> sockID;

	printf("Client %d connected.\n",index + 1);

	while(1)
	{

		char data[1024],trailer[20],output[1024];
		int clientNo;
		int read = recv(clientSocket,data,1024,0);
		data[read] = '\0';
		
		sprintf(trailer," [from client %d]",index + 1);

		if(strcmp(data,"LIST") == 0)
		{
			int l = 0;
			for(int i = 0 ; i < clientCount ; i ++)
			{
				if(i != index)
					l += snprintf(output + l,1024,"Client %d is at socket %d.\n",i + 1,Client[i].sockID);
			}

			send(clientSocket,output,1024,0);
			continue;
		}
		
		if(strcmp(data,"SEND") == 0)
		{
			read = recv(clientSocket,&clientNo,sizeof(clientNo),0); //read destination client id
			int id = ntohl(clientNo) - 1;
			
			read = recv(clientSocket,data,1024,0); //read message
			strcat(data,trailer);
			data[read + strlen(trailer)] = '\0';
			send(Client[id].sockID,data,1024,0);			
		}
	}
	return NULL;
}

int main()
{
	int serverSocket,opt = 1; 
	struct sockaddr_in serverAddr;
	
	if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("Couldn't create socket\n");
		return -1;
	}

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(8080);
	serverAddr.sin_addr.s_addr = htons(INADDR_ANY);
	
	setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt));
	
	if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1)
	{
		printf("Bind failed.\n");
		return -1;
	}

	if (listen(serverSocket, 1024) == -1)
	{
		printf("Listen failed.\n");
		return -1;
	}

	printf("Server listenting on port 8080.\n");

	while(1)
	{
		Client[clientCount].sockID = accept(serverSocket, (struct sockaddr*)&Client[clientCount].clientAddr, &Client[clientCount].len);
		Client[clientCount].index = clientCount;

		pthread_create(&thread[clientCount], NULL, doNetworking, (void*)&Client[clientCount]);

		clientCount++;
	}

	for(int i = 0; i < clientCount; i++)
		pthread_join(thread[i],NULL);

	return 0;
}
