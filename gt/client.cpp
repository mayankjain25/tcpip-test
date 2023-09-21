// client.cpp
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include "common.h"

int connectToServer(const char *ipAddress, int port)
{
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1)
    {
        std::cerr << "Error: Could not create socket" << std::endl;
        return -1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(ipAddress);

    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        std::cerr << "Error: Could not connect to server" << std::endl;
        close(clientSocket);
        return -1;
    }

    return clientSocket;
}

int sendData(int socket, const char *message)
{
    ssize_t sentBytes = send(socket, message, strlen(message), 0);
    if (sentBytes == -1)
    {
        std::cerr << "Error: Could not send data" << std::endl;
        return -1;
    }
    return 0;
}

int receiveResponse(int socket, char *responseBuffer, int bufferSize)
{
    ssize_t responseBytesReceived = recv(socket, responseBuffer, bufferSize, 0);
    if (responseBytesReceived == -1)
    {
        std::cerr << "Error: Could not receive response" << std::endl;
        return -1;
    }

    responseBuffer[responseBytesReceived] = '\0';
    return 0;
}

void closeConnection(int socket)
{
    close(socket);
}
