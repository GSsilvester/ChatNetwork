#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

int main(){

    int server_socket; //file_descriptor_server
    int client_socket;
    sockaddr_in server_address , client_address;
    socklen_t length_client ;
    
    //AF_INET == Internet Protocol V4 , SOCK_STREAM == TCP socket , 0 == Protocol IP
    server_socket = socket(AF_INET , SOCK_STREAM , IPPROTO_IP);

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY; //Any free IP address
 
    bind (server_socket , (const sockaddr *) &server_address , sizeof(server_address));

    listen (server_socket , 3);

    std::cout << "Server listening on 8080";

    length_client = sizeof(client_address);

    //server keep alive
    while(true){

        client_socket = accept (server_socket , (sockaddr * ) &client_address , &length_client);

        
        //Returns num > 0 if connected
        // num == -1 If it failed the connection
        if(client_socket == -1){

            std::cout << "Error" << std::endl;
            continue;

        }

        std::cout << "Client connected " << std::endl;

        char buffer [1024];

        int buffer_size {} ;

        //Continuing communication 
        while(true){

            memset(buffer , 0 , 1024);

            buffer_size = recv(client_socket , buffer , sizeof(buffer) , 0);
            
            if (buffer_size <= 0 ){

                std::cout << "Error" << std::endl;
                close(client_socket);
                break;

            }

            std::cout << "I've got the message : " << buffer << std::endl;

            std::string server_response;

            std::cout << "Send: " << std::endl;

            getline (std::cin , server_response);

            send(client_socket , server_response.c_str() , server_response.size() , 0);

        }

    }

    close (server_socket);

}   
