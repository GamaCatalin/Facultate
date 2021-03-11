#include <stdio.h>
#include <sys/types.h>


#ifdef _WIN32
#  include <WinSock2.h>
#  include <Ws2tcpip.h>
#  pragma comment(lib, "Ws2_32.lib")
#else
// Do something else here for non windows
#endif



struct sockaddr_in bindSocketToClient(SOCKET socket, short port) {
	struct sockaddr_in client;
	struct sockaddr_in wrongClient;
	wrongClient.sin_port = -1;

	client.sin_family = AF_INET;
	client.sin_port = htons(port);
	client.sin_addr.s_addr = inet_addr("192.168.0.121");
	if(bind(socket, (SOCKADDR*)&client, sizeof(client))==0){
		printf("Bind failed with error: %d\n", WSAGetLastError());
		return wrongClient;
	}
	return client;
}

SOCKET createSocket() {
	SOCKET sock;

	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock == INVALID_SOCKET) {
		printf("Socket failed with error %d\n", WSAGetLastError());
		return 1;
	}
	return sock;
}


int main(int argc, char *argv[]) {
	SOCKET sock = INVALID_SOCKET;
	WSADATA wsaData;
	struct sockaddr_in server,client;
	short port = 1234;

	char msgBuffer[1000]="sal kf!!";
	int msgLen = (int)(sizeof(msgBuffer) - 1);



	int res = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (res != NO_ERROR) {
		printf("WSAStartup failed with error \n");
		return 1;
	}


	sock = createSocket();
	if (sock == INVALID_SOCKET) {
		return 1;
	}

	client = bindSocketToClient(sock, port);
	if (client.sin_port == 1) {
		return 1;
	}
	
	puts("Sending datagram to server...");
	
	int clientResult = sendto(sock, msgBuffer, msgLen, 0, (SOCKADDR*)&client, (int)sizeof(client));
}