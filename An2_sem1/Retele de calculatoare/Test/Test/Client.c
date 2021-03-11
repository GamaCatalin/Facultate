#include <stdio.h>
#include <sys/types.h>
#include <thread>
#include <string>
#include <string.h>

#ifdef _WIN32
#  include <WinSock2.h>
#  include <Ws2tcpip.h>
#  pragma comment(lib, "Ws2_32.lib")
#else

#endif

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

struct sockaddr_in getAddrServer(struct sockaddr_in addr,int port) {
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(&addr, 0, sizeof(addr));
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

SOCKET createUDPSocket() {
	SOCKET sock;

	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock == INVALID_SOCKET) {
		printf("Socket failed with error %d\n", WSAGetLastError());
		return 1;
	}
	return sock;
}



int main(int argc, char* argv[]) {


	SOCKET tcpSocket = INVALID_SOCKET;
	SOCKET udpSocket = INVALID_SOCKET;
	WSADATA wsaData;
	struct sockaddr_in serverAddr, clientAddr;
	//struct sockeddr_in clientList[100];
	short serverPort = 7000;
	short clientPort = 5000;

	char msgBuffer[1000] = "";
	int msgLen = (int)(sizeof(msgBuffer) - 1);






	int res = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (res != NO_ERROR) {
		printf("WSAStartup failed with error \n");
		return 1;
	}


	//TCP socket for client

	tcpSocket = createTCPSocket();
	if (tcpSocket == INVALID_SOCKET) {
		return 1;
	}

	clientAddr = bindSocket(tcpSocket, clientPort);
	if (clientAddr.sin_port == 1) {
		return 1;
	}


	serverAddr = getAddrServer(serverAddr, serverPort);


	int con = connect(tcpSocket, (struct sockaddr_in*)&serverAddr, sizeof(struct sockaddr_in));

	if (con < 0) {
		printf("%s", "Error connecting to server!");
		return 1;
	}


	//UDP socket for client

	udpSocket = createUDPSocket();
	if (udpSocket == INVALID_SOCKET) {
		return 1;
	}




	for (;;) {
		fgets(msgBuffer, msgLen, stdin);

		if (strcmp(msgBuffer, "QUIT\n") == 0) {
			sendto(udpSocket, msgBuffer, msgLen, 0, &serverAddr, sizeof(serverAddr));
			closesocket(tcpSocket);
			closesocket(udpSocket);
			return 1;
		}

	}



	return 1;
}