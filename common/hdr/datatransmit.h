#ifndef DATATRANSMIT_H
#define DATATRANSMIT_H

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <fcntl.h>

//#define socket_name "/tmp/socket"
const char* const file_server = "/tmp/socket";
const char* const file_client = "/tmp/client";

class DataTransmit
{
public:
    DataTransmit();
    ~DataTransmit();

    void createServer();
    void createClient();

    int receive(void *buf, size_t size);
    int send(const void *buf, size_t size);

    int srvReceive(void *buf, size_t size);
    int srvSend(const void *buf, size_t size);
    int clntReceive(void *buf, size_t size);
    int clntSend(const void *buf, size_t size);

    void endTransmit();

private:
//    rs485 *_rs485;

    int server;
    int client;
    struct sockaddr_un server_addr;
    struct sockaddr_un client_addr;
};

#endif // DATATRANSMIT_H
