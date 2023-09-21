#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int clientSocketCreation();
int connectClientToServer();
int sendMessageToServer();
int receiveMessageFromServer();