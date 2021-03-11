#include <stdio.h>
#include <sys/types.h>
#include <thread>

#ifdef _WIN32
#  include <WinSock2.h>
#  include <Ws2tcpip.h>
#  pragma comment(lib, "Ws2_32.lib")
#else

#endif


#define PORT 7000;
#define _CRT_SECURE_NO_WARNINGS

struct sockaddr_in bindSocket(SOCKET socket, short port) {
	struct sockaddr_in client;
	struct sockaddr_in wrongClient;
	wrongClient.sin_port = -1;

	client.sin_family = AF_INET;
	client.sin_port = htons(port);
	client.sin_addr.s_addr = ADDR_ANY;
	memset(&client, 0, sizeof(client));
	if (bind(socket, (SOCKADDR*)&client, sizeof(client)) == 0) {
		printf("Bind failed with error: %d\n", WSAGetLastError());
		return wrongClient;
	}
	return client;
}

SOCKET createTCPSocket() {
	SOCKET sock;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) {
		printf("Socket failed with error %d\n", WSAGetLastError());
		return 1;
	}
	return sock;
}


char* getIPAddress(int sock) {
	struct sockaddr_in addr;
	getsockname(sock, &addr, sizeof(addr));
	return inet_ntoa(addr.sin_addr);
}


void sendToAll(char* buffer, int bufferSize,int fdMax,fd_set masterFD,SOCKET serverSock) {
	int i;
	for (i = 0; i <= fdMax; i++) {
		if (FD_ISSET(i, &masterFD)) {
			if (i != serverSock) {
				if (send(i, buffer, bufferSize, 0) == -1) {
					printf("Send failed with error %d\n",WSAGetLastError());
					return 1;
				}
			}
		}
	}
}

int main(int argc, char* argv[]) {


	SOCKET tcpSocket = INVALID_SOCKET;
	WSADATA wsaData;
	struct sockaddr_in serverAddr, clientAddr;
	int addrLen;
	short port = 7000;
	fd_set masterFD;
	fd_set readingFD;
	int fdMax, fdNew,current;
	int nrClients=0;
	int bytesReceived;

	char msgBuffer[1000];
	int msgLen = (int)(sizeof(msgBuffer) - 1);






	int res = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (res != NO_ERROR) {
		printf("WSAStartup failed with error \n");
		return 1;
	}


	//TCP socket for server

	tcpSocket= createTCPSocket();
	if (tcpSocket == INVALID_SOCKET) {
		return 1;
	}

	serverAddr = bindSocket(tcpSocket, port);
	if (serverAddr.sin_port == 1) {
		return 1;
	}


	FD_ZERO(&masterFD);
	FD_ZERO(&readingFD);


	





	if (listen(tcpSocket, 10) == -1) {
		printf("Listen failed with error %d\n", WSAGetLastError());
		return 1;
	}


	FD_SET(tcpSocket, &masterFD);
	fdMax = &tcpSocket;


	for (;;) {
		readingFD = masterFD;
		if (select(fdMax + 1, &readingFD, NULL, NULL, NULL) == -1) {
			printf("Select failed with error %d\n", WSAGetLastError());
			return 1;
		}

		for (int i = 0; i <= fdMax; i++) {
			if (FD_ISSET(i, &readingFD)) {
				current = i;
			}
			if (i == tcpSocket) {
				addrLen = sizeof(clientAddr);
				if (fdNew = accept(tcpSocket, (struct sockaddr_in*)&clientAddr, addrLen) == -1) {
					printf("Accept failed with error %d\n", WSAGetLastError());
					return 1;
				}
				else {
					FD_SET(fdNew, &masterFD);
					if (fdNew > fdMax) {
						fdMax = fdNew;
					}
					printf("SERVER: %s connected on socket %d\n", getIPAddress(fdNew), fdNew);
					nrClients++;
					printf_s(msgBuffer, "Succesfully connected to server, there are currently %d clients connected\n", nrClients);
					send(fdNew, msgBuffer, strlen(msgBuffer) + 1, 0);

					//Send all clients
					for (int j = 0; j <= fdMax; j++) {
						printf_s(msgBuffer, "%s\n", getIPAddress(j));
						send(fdNew, msgBuffer, strlen(msgBuffer) + 1, 0);
					}

				}
			}
			else {
				if (bytesReceived = recv(i, msgBuffer, sizeof(msgBuffer), 0) <= 0) {
					printf("Receive failed with error %d\n", WSAGetLastError());
					return 1;
				
				if (bytesReceived == 0) {
					printf("Client %d disconected", i);
				}
				else {
					printf("Receive failed with error %d\n", WSAGetLastError());
					return 1;
				}
				nrClients--;
				close(i);
				FD_CLR(i, &masterFD);
				
				}
				else {
					msgBuffer[bytesReceived] = 0;
					if (strcmp("QUIT\n", msgBuffer) == 0) {
						printf_s(msgBuffer, "Disconnecting...");
						send(i, msgBuffer, sizeof(msgBuffer), 0);

						printf_s(msgBuffer, "Client %s disconected.", getIPAddress(i));
						sendToAll(msgBuffer, sizeof(msgBuffer), fdMax, masterFD, tcpSocket);
						nrClients--;
						close(i);
						FD_CLR(i, &masterFD);
					}
					else {

					}
				}
			
			}
		
		}
	}




}