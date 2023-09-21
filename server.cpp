#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    // Create a socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1)
    {
        std::cerr << "Error: Could not create socket" << std::endl;
        return 1;
    }

    // Bind the socket to a specific IP and port
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Change this port as needed
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        std::cerr << "Error: Could not bind to port" << std::endl;
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1)
    {
        std::cerr << "Error: Could not listen for connections" << std::endl;
        return 1;
    }

    std::cout << "Server listening on port 12345" << std::endl;

    while (true)
    {
        // Accept incoming connection
        sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen);
        if (clientSocket == -1)
        {
            std::cerr << "Error: Could not accept connection" << std::endl;
            return 1;
        }

        // Receive data from the client
        char buffer[1024];
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived == -1)
        {
            std::cerr << "Error: Could not receive data" << std::endl;
            return 1;
        }

        // Null-terminate the received data
        buffer[bytesReceived] = '\0';

        // Print the received message
        std::cout << "Received message from client: " << buffer << std::endl;

        // Send an ACK response to the client
        const char *ackMessage = "ACK";
        if (send(clientSocket, ackMessage, strlen(ackMessage), 0) == -1)
        {
            std::cerr << "Error: Could not send ACK response" << std::endl;
            return 1;
        }

        // Close the client socket
        close(clientSocket);
    }

    // Close the server socket (never reached)
    close(serverSocket);

    return 0;
}
