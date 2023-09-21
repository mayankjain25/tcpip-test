#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int createServerSocket();
int bindSocketToIP();
int listenToIncomingCommunication();

int clientSocketCreation();
int connectClientToServer();
int sendMessageToServer();
int receiveMessageFromServer();