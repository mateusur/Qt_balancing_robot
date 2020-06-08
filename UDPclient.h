#ifndef UDP_CLIENT_H
#define UDP_CLIENT_H

#include <winsock2.h>
#include <string>

struct UDP_t
{
    sockaddr_in serverAddr;
    sockaddr_in clientAddr;

    int clientSock;
    int len;
};

bool UDPclient_init(int clientPort);

bool UDPclient_setSeverIPAddress(const char* IPserver, int serverPort);
bool UDPclient_sendReq(const char* buffer, int buffSize);
bool UDPclient_getResp(char* buffer, int bufferSize);

#endif
