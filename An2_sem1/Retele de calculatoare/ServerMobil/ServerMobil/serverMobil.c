// Server side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 


#ifdef _WIN32
#  include <WinSock2.h>
#  include <Ws2tcpip.h>
#  include <ws2ipdef.h>
#  pragma comment(lib, "Ws2_32.lib")
#else
// Do something else here for non windows
#endif

#define PORT     1234
#define MAXLINE  1024 
#define EXITMSG  "stop\n"


SOCKET createSocket() {
    SOCKET sock;
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock == INVALID_SOCKET) {
        printf("Socket failed with error %d\n", WSAGetLastError());
        return INVALID_SOCKET;
    }
    return sock;
}

struct sockaddr_in createClientAddress(char* clientIP) {
    struct sockaddr_in client;

    client.sin_family = AF_INET;
    client.sin_port = htons(PORT);
    inet_pton(AF_INET,clientIP,&client.sin_addr.s_addr);

    return client;
}

struct sockaddr_in createServerAddress(char* serverIP) {
    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET,serverIP,&server.sin_addr.s_addr);

    return server;
}

int bindSocket(SOCKET sock,struct sockaddr_in server) {
    if (bind(sock, (SOCKADDR*)&server, sizeof(server)) != 0) {
        printf("Bind failed with error: %d\n", WSAGetLastError());
        return -1;
    }
    return 1;
}


int listenToClient(SOCKET sock,struct sockaddr_in client) {
    int len, n;
    char buffer[MAXLINE];

    len = sizeof(client);  //len is value/resuslt 

    n = recvfrom(sock, (char*)buffer, MAXLINE, 0, (struct sockaddr*)&client, &len);


    if (n > 0) {
        //printf("Client raw : %s\n", buffer);
        buffer[n] = '\0';
        printf("Client : %s\n", buffer);
        
        
        if (strcmp(EXITMSG,buffer)==0) {
            return 0;
        }

        //printf("Compare: %d\n", strcmp("stop\n", buffer));

        return 1;
    }
    else if (n == 0) {
        printf("Connection closed!\n");
        return 0;
    }
    else {
        printf("Recv Error: %d\n", WSAGetLastError());
        return 0;
    }

    return 0;
}


int main() {
    char buffer[MAXLINE];
    WSADATA wsaData;
    struct sockaddr_in servaddr, cliaddr;
    SOCKET sock;
    char* serverIP = "192.168.1.146";
    char* clientIP = "192.168.1.245";

    int res = WSAStartup(MAKEWORD(2, 2), &wsaData);

    if (res != NO_ERROR) {
        printf("WSAStartup failed with error \n");
        return 1;
    }

    sock = createSocket();

    if (sock == INVALID_SOCKET) {
        return -1;
    }


    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr = createServerAddress(serverIP);
    cliaddr = createClientAddress(clientIP);


    if (bindSocket(sock,servaddr) < 0) {
        return -1;
    }



    while (1) {
        if (listenToClient(sock, cliaddr) == 0) {
            break;
        }
    }

   
    

    closesocket(sock);
    return 0;
}