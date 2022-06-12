#ifndef CLIENT_H_
#define CLIENT_H_

using namespace std;

#include <iostream> //cout
#include <string.h> //strlen
#include <string> //string
#include <sys/socket.h> //socket -----
#include <arpa/inet.h> //inet_addr ------
#include <netdb.h> //hostent  ----
#include <thread>
#include <unistd.h>//sleep

class Client
{
    private:
        Client(string address_,int port_):sock(-1),port(port_),address(address_){};
        
        static Client* client_ ; //= nullpt -> a member with an in-class initializer must be const

        int sock;
        int port;
        string address; 

        struct sockaddr_in server;
        string Receive(int);
        //thread client_thread;

    public:
        static Client *GetInstance(string, int);
        void Connect();
        bool sendData(string);
        thread app_thr;
        
};

#endif //CLIENT_H_