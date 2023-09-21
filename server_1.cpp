#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int serverSocket;
int bindSocketValue;
int listenValue;
int clientSocket;
int clientConnect;

int createServerSocket()
{
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    return serverSocket;

    // serverSocket returns -1 on unsuccessful socket creation, else a non negative number.
}

int bindSocketToIP()
{
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Change this port as needed
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bindSocketValue = bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    return bindSocketValue;

    // Upon successful completion, bind() shall return 0, otherwise -1 shall be returned;
}

int listenToIncomingCommunication()
{

    listenValue = listen(serverSocket, 5); // Upon successful completion, listen() shall return 0, otherwise -1 will be returned.
    return listenValue;
}

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