// main.cpp
#include <iostream>
#include "common.h"

int main()
{
    const char *serverIP = "127.0.0.1"; // Replace with the actual server IP
    int serverPort = 12345;             // Replace with the actual server port
    const char *message = "Hello, server!";
    const char *ackMessage = "ACK";

    // Create a client socket and connect to the server
    int clientSocket = connectToServer(serverIP, serverPort);
    if (clientSocket == -1)
    {
        return 1;
    }

    // Send a message to the server
    if (sendData(clientSocket, message) == -1)
    {
        closeConnection(clientSocket);
        return 1;
    }

    // Receive a response from the server
    char responseBuffer[1024];
    if (receiveResponse(clientSocket, responseBuffer, sizeof(responseBuffer)) == -1)
    {
        closeConnection(clientSocket);
        return 1;
    }

    std::cout << "Received response from server: " << responseBuffer << std::endl;

    // Close the client connection
    closeConnection(clientSocket);

    return 0;
}
