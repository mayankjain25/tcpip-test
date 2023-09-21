#include <gtest/gtest.h>
#include "client.cpp"
#include "server.cpp"

// Test cases for client functions
TEST(ClientTest, ConnectToServerSuccess)
{
    int socket = connectToServer("127.0.0.1", 12345);
    EXPECT_GT(socket, 0); // Check that socket is a valid descriptor
}

TEST(ClientTest, ConnectToServerFailure)
{
    int socket = connectToServer("invalid_ip", 12345);
    EXPECT_EQ(socket, -1); // Check that socket is -1 on failure
}

// Test cases for server functions
TEST(ServerTest, StartServerSuccess)
{
    int socket = startServer(12345);
    EXPECT_GT(socket, 0); // Check that socket is a valid descriptor
}

TEST(ServerTest, StartServerFailure)
{
    int socket = startServer(99999); // Port that is likely unavailable
    EXPECT_EQ(socket, -1);           // Check that socket is -1 on failure
}

// Test cases for send and receive functions can be added similarly

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
