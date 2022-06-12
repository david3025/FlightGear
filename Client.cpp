

#include "Client.h"

void connec(int sock,string address,struct sockaddr_in server);

Client* Client::GetInstance(string address_ , int port_){
    
    if(client_==nullptr)
    {
        client_ = new Client(address_,port_);
    }
    return client_;
}
        

Client* Client::client_= nullptr;

void Client::Connect()
{
    if(sock == -1)
    {
        sock = socket(AF_INET , SOCK_STREAM , 0);
        if (sock == -1)
        {
            std::cerr << "Could not create a socket" << std::endl;
        }
    }
    else { 
        cout << "socket is already created"<<endl;
    }

    if(inet_addr(address.c_str()) == ( in_addr_t)-1)
    {
        struct hostent *he;
        struct in_addr **addr_list;

        if ( (he = gethostbyname( address.c_str() ) ) == NULL)
        {
            herror("gethostbyname");
            cout<<"Failed to resolve hostname\n";

        }

        addr_list = (struct in_addr **) he->h_addr_list;

        for(int i = 0; addr_list[i] != NULL; i++)
        {
            server.sin_addr = *addr_list[i];

            cout<<address<<" resolved to "<<inet_ntoa(*addr_list[i])<<endl;

            break;
        }
    }

    else
    {
        server.sin_addr.s_addr = inet_addr( address.c_str() );
    }

    server.sin_family = AF_INET;
    server.sin_port = htons( 5402 );

    connec(sock, address, server);
    //client_thread = std::thread(connec, sock, address, server);
    cout<< "client connect";
    
    //connec(sock, address, server);
    sleep(3);
    //sendData("set controls/flight/rudder 1");
    
}

bool Client::sendData(string data)
{
    cout<<"\t( send command: "<< data<<" )"<<endl;
   
    string msg = data +"\r\n";

    if( send(sock , msg.c_str() , strlen( msg.c_str() ) , 0) < 0)
    {
        std::cerr << "Send failed : " << std::endl;
        return false;
    }

    Receive(512);
    
    return true;
}

string Client::Receive(int size)
{
    char buffer[size];
    if( recv(sock , buffer , sizeof(buffer) , 0) < 0)
    {
        puts("recv failed");
        return NULL;
    }
    return buffer;
}

void connec(int sock,string address,struct sockaddr_in server)
{
    if( connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0 )
    {
        std::cerr << "connect failed. Error" << std::endl;
    }
    cout<<"Connected to client\n";
}

