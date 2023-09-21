#ifndef COMMON_H
#define COMMON_H

void closeConnection(int socket);
int connectToServer(const char *ipAddress, int port);
int sendData(int socket, const char *message);
int receiveResponse(int socket, char *responseBuffer, int bufferSize);

// Other common declarations or includes as needed

#endif // COMMON_H
