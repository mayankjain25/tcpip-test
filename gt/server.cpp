// server.cpp
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include "common.h"

int startServer(int port)
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1)
    {
        std::cerr << "Error: Could not create socket" << std::endl;
        return -1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        std::cerr << "Error: Could not bind to port" << std::endl;
        close(serverSocket);
        return -1;
    }

    if (listen(serverSocket, 5) == -1)
    {
        std::cerr << "Error: Could not listen for connections" << std::endl;
        close(serverSocket);
        return -1;
    }

    std::cout << "Server listening on port " << port << std::endl;

    return serverSocket;
}

int acceptConnection(int serverSocket)
{
    sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen);
    if (clientSocket == -1)
    {
        std::cerr << "Error: Could not accept connection" << std::endl;
        return -1;
    }

    return clientSocket;
}

int receiveData(int clientSocket, char *buffer, int bufferSize)
{
    ssize_t receivedBytes = recv(clientSocket, buffer, bufferSize, 0);
    if (receivedBytes == -1)
    {
        std::cerr << "Error: Could not receive data" << std::endl;
        return -1;
    }

    buffer[receivedBytes] = '\0';
    return 0;
}

int sendAck(int clientSocket, const char *ackMessage)
{
    ssize_t sentBytes = send(clientSocket, ackMessage, strlen(ackMessage), 0);
    if (sentBytes == -1)
    {
        std::cerr << "Error: Could not send ACK response" << std::endl;
        return -1;
    }
    return 0;
}

void closeConnection(int socket)
{
    close(socket);
}
