#include "../../common/hdr/datatransmit.h"

DataTransmit::DataTransmit()
{
    //    _rs485 = new rs485();
    //    _rs485->receive();
    //    _rs485->close();
}

DataTransmit::~DataTransmit()
{
    //    delete  _rs485;
}

void DataTransmit::createServer()
{
    server = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server < 0)
    {
        perror("-socket error\n");
        exit(1);
    }
    else
    {
        std::cout << "create server socket" << std::endl;
    }

    unlink(file);
    bzero(&server_addr, sizeof(server_addr));

    server_addr.sun_family = AF_LOCAL;
    strcpy(server_addr.sun_path, file);

    if (bind (server, (struct sockaddr*)&server_addr, /*server_add_len*/ SUN_LEN (&server_addr)) < 0)
    {
        perror("-bind error");
        exit(1);
    }

    if (listen (server, 1) == -1)
    {
        perror("-listen error");
        exit(1);
    }
    else
    {
        std::cout << "listen ok " << std::endl;
    }

    socklen_t client_add_len = sizeof (server_addr);
    client = accept (server, (struct sockaddr*)&client_addr, &client_add_len);
    if (client < 0)
    {
        perror("-accept error\n");
        exit(1);
    }
    else
    {
        std::cout << "accept ok " << client << std::endl;
    }

    if (fcntl(client, F_SETFL, O_NONBLOCK) != 0)
    {
        perror("-fcntl error\n");
        exit(1);
    }
}

void DataTransmit::createClient()
{
    if ((client = socket(AF_LOCAL, SOCK_STREAM, 0)) < 0)
    {
        perror("-socket error\n");
        exit(1);
    }
    else
    {
        std::cout << "create client socket" << std::endl;
    }

    bzero(&client_addr, sizeof (client_addr));
    client_addr.sun_family = /*AF_UNIX*/AF_LOCAL;
    strcpy(client_addr.sun_path, file);

    if (connect (client, (struct sockaddr*)&client_addr, SUN_LEN (&client_addr)) < 0)
    {
        perror("-connect error\n");
        exit(1);
    }
    else
    {
        std::cout << "connect ok" << std::endl;
    }

    if (fcntl(client, F_SETFL, O_NONBLOCK)!=0)
    {
        perror("-fcntl error\n");
        exit(1);
    }
}

int DataTransmit::receive(void *buf, size_t size)
{
    int bytes_recv = read(client, buf, sizeof(size));

    return bytes_recv;
}

int DataTransmit::send(const void *buf, size_t size)
{
    int bytes_send = write(client, buf, size);

    return bytes_send;
}

void DataTransmit::endTransmit()
{
    close (server);
    unlink (file);
}
