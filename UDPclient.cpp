#include <iostream>
#include <Ws2tcpip.h>

#include "UDPclient.h"

static UDP_t hUDP;

bool UDPclient_init(int clientPort)
{
// Memory setup
    memset(&hUDP.clientAddr, 0, sizeof(hUDP.clientAddr));
    memset(&hUDP.serverAddr, 0, sizeof(hUDP.serverAddr));
    hUDP.len = sizeof(sockaddr);

// Windows socket startup
    WSADATA wsaData;
    WSAStartup(0x0202, &wsaData);

// Create socket
    hUDP.clientAddr.sin_family = AF_INET;
    hUDP.clientAddr.sin_addr.s_addr = INADDR_ANY;
    hUDP.clientAddr.sin_port = htons((u_short)clientPort);

    hUDP.clientSock = socket(PF_INET, SOCK_DGRAM, 0);
    if ( hUDP.clientSock < 0)
    {
        std::cerr << "socket creating failed" << std::endl;
        return false;
    }

// Bind a client address and port
    if (bind(hUDP.clientSock, (LPSOCKADDR)&hUDP.clientAddr, hUDP.len) < 0)
    {
        std::cerr << "bind failed" << std::endl;
        return false;
    }

// set timeout
    int iTimeout = 1000;
    setsockopt(hUDP.clientSock, SOL_SOCKET, SO_RCVTIMEO,
                     (const char*)&iTimeout, sizeof(iTimeout));

    return true;
}

bool UDPclient_setSeverIPAddress(const char* IPserver, int serverPort)
{
    hUDP.serverAddr.sin_family = AF_INET;

    hUDP.serverAddr.sin_addr.s_addr = inet_addr(IPserver);
    if (hUDP.serverAddr.sin_addr.s_addr == INADDR_NONE)
    {
        std::cerr << "bad ip address:" << IPserver << std::endl;
        return false;
    }

    if (serverPort > 0)
    {
        hUDP.serverAddr.sin_port = htons(serverPort);
    }
    else
    {
        std::cerr << "bad port number: " << serverPort << std::endl;
        return false;
    }

    return true;
}

bool UDPclient_sendReq(const char* buffer, int buffSize)
{
    sendto(hUDP.clientSock, buffer, buffSize, 0, (LPSOCKADDR)&hUDP.serverAddr, hUDP.len);

    return true;
}

bool UDPclient_getResp(char* buffer, int bufferSize)
{
    memset((char*)buffer, 0, bufferSize);
    recvfrom(hUDP.clientSock, buffer, bufferSize, 0, (LPSOCKADDR)&hUDP.serverAddr, &hUDP.len);

    return true;
}
