// server_main.cpp
#include "server.cpp"

int main()
{
    int serverPort = 12345; // Replace with the desired server port
    const char *ackMessage = "ACK";

    int serverSocket = startServer(serverPort);
    if (serverSocket == -1)
    {
        return 1;
    }

    while (true)
    {
        int clientSocket = acceptConnection(serverSocket);
        if (clientSocket == -1)
        {
            closeConnection(serverSocket);
            return 1;
        }

        char buffer[1024];
        if (receiveData(clientSocket, buffer, sizeof(buffer)) == -1)
        {
            closeConnection(clientSocket);
            closeConnection(serverSocket);
            return 1;
        }

        std::cout << "Received message from client: " << buffer << std::endl;

        if (sendAck(clientSocket, ackMessage) == -1)
        {
            closeConnection(clientSocket);
            closeConnection(serverSocket);
            return 1;
        }

        closeConnection(clientSocket);
    }

    // Close the server socket (never reached)
    close(serverSocket);

    return 0;
}
