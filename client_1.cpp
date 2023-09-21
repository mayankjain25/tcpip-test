#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int clientSocket;
int clientConnect;

int clientSocketCreation()
{

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    return clientSocket;
}

int connectClientToServer()
{
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345);                  // Change this port to match the server
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change this IP to match the server

    clientConnect = connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    return clientConnect;
}

int sendMessageToServer()
{
    const char *message = "Hello, server!";
    return send(clientSocket, message, strlen(message), 0);
}

int receiveMessageFromServer()
{
    char ackBuffer[1024];
    int ackBytesReceived = recv(clientSocket, ackBuffer, sizeof(ackBuffer), 0);
    return ackBytesReceived;
}