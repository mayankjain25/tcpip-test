#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
using namespace std;

int main()
{
    // Create a socket

    while (true)
    {
        int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (clientSocket == -1)
        {
            cerr << "Error: Could not create socket" << endl;
            return 1;
        }

        // Connect to the server
        sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(12345);
        serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

        if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
        {
            cerr << "Error: Could not connect to server" << endl;
            return 1;
        }
        // Send a message to the server
        const char *message = "Hello, server!";
        if (send(clientSocket, message, strlen(message), 0) == -1)
        {
            cerr << "Error: Could not send data" << endl;
            break; // Exit the loop on send error
        }

        // Receive the ACK response from the server
        char ackBuffer[1024];
        int ackBytesReceived = recv(clientSocket, ackBuffer, sizeof(ackBuffer), 0);
        if (ackBytesReceived == -1)
        {
            cerr << "Error: Could not receive ACK response" << endl;
            break;
        }

        // Null-terminate the ACK data
        ackBuffer[ackBytesReceived] = '\0';

        // Print the ACK response
        cout << "Received ACK from server: " << ackBuffer << endl;

        // Sleep for a while before sending the next message
        close(clientSocket);
        sleep(1);
    }

    // Close the socket when done

    return 0;
}
