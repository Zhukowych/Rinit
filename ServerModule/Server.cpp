
#include "Server.hpp"

void Server::CreateServer(){
	CreateServerSocket();
	SetSockOpt();
	SetServerAddress();
	BindAddress();
	Listen();
	Accept();
}

void Server::CreateServerSocket(){
    if ((ServerSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        logger.ErrorLog("Socket creation failed");
        exit(EXIT_FAILURE);
    }
}

void Server::SetSockOpt(){
    if (setsockopt(ServerSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        logger.ErrorLog("SetSockOpt failed");
        exit(EXIT_FAILURE);
    }
}

void Server::SetServerAddress(){
	ServerAddress.sin_family = AF_INET;
	ServerAddress.sin_addr.s_addr = INADDR_ANY;
	ServerAddress.sin_port = htons( PORT );
}

void Server::BindAddress(){
    if (bind(ServerSocket, (struct sockaddr *)&ServerAddress, sizeof(ServerAddress))<0)
    {
        logger.ErrorLog("Error in bind");
        exit(EXIT_FAILURE);
    }
}

void Server::Listen(){
    if(listen(ServerSocket, 3) < 0)
    {
        logger.ErrorLog("Error in listen");
        exit(EXIT_FAILURE);
    }
}

void Server::Accept(){
	while(1){
		ClientSocket = accept(ServerSocket, (struct sockaddr *)&ServerAddress,  (socklen_t*)&ServerAddress);
		ReceivedBytes = read(ClientSocket, ReceivedCommand, RESEIVED_COMMAND_MAX_LENGTH);
	    IRequestHandler* handler = CreateRequestHandler();
	    handler->Handle();
	}
}

IRequestHandler* Server::CreateRequestHandler(){
	return new RequestHandler(ReceivedCommand, ClientSocket);
}

