#include "Server.h"
void connection();
void updateDB(int acceptFD,int buffer_len);
void openServerAndUpdateDB(int port);

Server* Server::GetInstance(int port_){
    
    if(server_==nullptr)
    {
        server_ = new Server(port_);
    }
    return server_;
}

Server* Server::server_= nullptr;


void Server::openServer()
{
    server_thread = thread(openServerAndUpdateDB,port);
}

void openServerAndUpdateDB(int port)
{
    sockaddr_in sockaddr;
    // Create a socket (IPv4, TCP)
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD == -1) 
    {
        cout << "Failed to create socket. errno: " << errno <<endl;
        exit(EXIT_FAILURE);
    }

    // Listen to port on any address
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = INADDR_ANY;
    sockaddr.sin_port = htons(port);                      // htons -> convert a number to network byte order
    if (bind(socketFD, (struct sockaddr*)&sockaddr, sizeof(sockaddr)) < 0) 
    {
        cout << "Failed to bind to port . errno: " << errno << endl;
        exit(EXIT_FAILURE);
    }

    // start listening (hold at most 10 connections in the queue)
    if (listen(socketFD, 10) < 0)
    {
        cout << "Failed to listen on socket. errno: " << errno << endl;
        exit(EXIT_FAILURE);
    }

    // grab a connection (from the queue)
    auto addrlen = sizeof(sockaddr);
    cout<<"wating for simulator connect..."<<endl;
    
    int acceptFD = accept(socketFD, (struct sockaddr*)&sockaddr, (socklen_t*)&addrlen);
    updateDB(acceptFD, BUFF_LEN);
}

void updateDB(int acceptFD,int buffer_len)
{
    char buffRecv[buffer_len];
    DB* dataBase =  DB::GetInstance();

    while(true)
    {
        read(acceptFD, buffRecv, buffer_len);
        dataBase->updateData(buffRecv, buffer_len);
    }
}