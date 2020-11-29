
#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include "../LoggerModule/Logger.hpp"
#include "../RequestHandler/IRequestHandler.hpp"
#include "../RequestHandler/RequestHandler.hpp"

const int PORT = 8000;
const int RESEIVED_COMMAND_MAX_LENGTH = 8;
// TODO: global settings module

class Server{
public:
	void CreateServer();
private:
	struct sockaddr_in ServerAddress;
	int ServerAddressLen = sizeof(ServerAddress);
	int ServerSocket, ClientSocket, ReceivedBytes;;
	int opt = 1;
	char *ReceivedCommand = new char[RESEIVED_COMMAND_MAX_LENGTH];
	Logger logger;
	void CreateServerSocket();
	void SetSockOpt();
	void SetServerAddress();
	void BindAddress();
	void Listen();
	void Accept();
	IRequestHandler* CreateRequestHandler();
};

#endif
