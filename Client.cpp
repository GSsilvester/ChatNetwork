#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

int main(){

    int client_socket;
    sockaddr_in server_address;
    
    client_socket = socket(AF_INET , SOCK_STREAM , IPPROTO_IP);

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    connect (client_socket , (const sockaddr *) &server_address , sizeof(server_address));

    std::cout << "Client started on port 8080";

    char buffer[1024];

    while(true){

        std::string client_response;

        std::cout << "Send: " ;

        getline(std::cin , client_response);

        send(client_socket , client_response.c_str() , client_response.size() , 0 );

        memset(buffer , 0 , 1024);

        recv(client_socket , buffer , sizeof(buffer) , 0 );

        std::cout << "Am primit de la server mesajul : " << buffer << std::endl;

    }

    close(client_socket);

}
