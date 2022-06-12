
#ifndef SERVER_H_
#define SERVER_H_

#include <sys/socket.h> // socket 
#include <netinet/in.h> // sockaddr_in
#include <cstdlib> // exit() and EXIT_FAILURE
#include <iostream>
#include <unistd.h> // read
#include <thread>
#include "dataBase.h"

#define BUFF_LEN  4096
class Server
{
    private:
        Server(int port_): port(port_){};
        static Server* server_ ; //= nullpt -> a member with an in-class initializer must be const
        thread server_thread;
        int acceptFD;
        int socketFD;
        int port;
    public:
        ~Server(){close(acceptFD);close(socketFD);};
        static Server *GetInstance(int);
        void openServer();
};

#endif //SERVER_H_

