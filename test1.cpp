#include "server_1.h"
#include "client_1.h"
#include <gtest/gtest.h>

// TESTS FOR SERVER
//  Testing for a positive socket creation
TEST(SocketCreation, positiveSocketCreation)
{
    int testValue = createServerSocket();
    EXPECT_GT(testValue, -1); // for every sucessful socket creation, the createServerSocket() function will return a non negative value.
}

TEST(SocketBinding, testForBindindSocket)
{
    int testValue = bindSocketToIP(); // for every sucessful socket bind, the bindSocketToIP() function will return a zero value
    EXPECT_EQ(testValue, 0);
}

TEST(SocketListening, testForSocketListening)
{
    int listenValue = listenToIncomingCommunication();
    EXPECT_EQ(listenValue, 0);
}

// // TESTS FOR CLIENT
TEST(ClientSocketCreation, testForClientSocket)
{
    int testValue = clientSocketCreation();
    EXPECT_GT(testValue, -1);
}

TEST(ClientSocketConnection, testForClientConnectionToServer)
{
    int testValue = connectClientToServer(); // Upon successful connection, connect() shall return 0, otherwise -1;
    EXPECT_GT(testValue, -1);
}

TEST(ClientMsgToServer, testingClientMessageToServer)
{
    int testValue = sendMessageToServer(); // Upon successful completion, send() should return the number of bytes sent, else return -1;
    EXPECT_GT(testValue, -1);
}

// TEST(ClientRecvMsgFromServer, testClientRecvMsg)
// {
//     int testValue = receiveMessageFromServer(); // Upon successful creation, recv() shall return the length of the message in bytes. If no messages are avaiable, it returns 0;

//     EXPECT_EQ(testValue, 0);
// }