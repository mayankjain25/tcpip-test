#include <gtest/gtest.h>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

TEST(ServerTest, CanBindToPort)
{
    // Create a socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    EXPECT_NE(serverSocket, -1);

    // Bind the socket to a specific IP and port
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Change this port as needed
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    EXPECT_EQ(bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)), 0);

    // Close the socket
    close(serverSocket);
}

TEST(ServerTest, CanListenForConnections)
{
    // Create a socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    EXPECT_NE(serverSocket, -1);

    // Bind the socket to a specific IP and port
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Change this port as needed
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    EXPECT_EQ(bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)), 0);

    // Listen for incoming connections
    EXPECT_EQ(listen(serverSocket, 5), 0);

    // Close the socket
    close(serverSocket);
}

TEST(ServerTest, CanReceiveData)
{
    // Create a socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    EXPECT_NE(serverSocket, -1);

    // Bind the socket to a specific IP and port
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Change this port as needed
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    EXPECT_EQ(bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)), 0);

    // Listen for incoming connections
    EXPECT_EQ(listen(serverSocket, 5), 0);

    // Accept incoming connection
    sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen);
    EXPECT_NE(clientSocket, -1);

    // Receive data from the client
    char buffer[1024];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    EXPECT_NE(bytesReceived, -1);

    // Close the client socket
    close(clientSocket);

    // Close the server socket
    close(serverSocket);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
