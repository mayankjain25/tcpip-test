// client_main.cpp
#include "client.cpp"

int main()
{
    const char *serverIP = "127.0.0.1"; // Replace with the actual server IP
    int serverPort = 12345;             // Replace with the actual server port
    const char *message = "Hello, server!";

    int clientSocket = connectToServer(serverIP, serverPort);
    if (clientSocket == -1)
    {
        return 1;
    }

    if (sendData(clientSocket, message) == -1)
    {
        closeConnection(clientSocket);
        return 1;
    }

    char responseBuffer[1024];
    if (receiveResponse(clientSocket, responseBuffer, sizeof(responseBuffer)) == -1)
    {
        closeConnection(clientSocket);
        return 1;
    }

    std::cout << "Received response from server: " << responseBuffer << std::endl;

    closeConnection(clientSocket);
    return 0;
}
