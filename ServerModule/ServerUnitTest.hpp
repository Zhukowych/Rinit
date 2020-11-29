
#ifndef SERVER_UNIT_TEST_HPP_
#define SERVER_UNIT_TEST_HPP_

#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h> 
#include <stdlib.h>
#include <iostream>
using namespace std;
const int PORT = 8000;

class ServerClient{
public:
	void Connect();
	void SendCommand(const char* messange);
	void WaitForClose();
private:
	int ClientSocket, opt;
	struct sockaddr_in ServerAddress;
	void CreateSocket();
	void SetServerAdderss();
	void SetInetPton();
	void ConnectToServer();
};

class ServerUnitTest{
public:
	void Test();
private:
	ServerClient client;
	const char* COMMAND = "11111111";
};
  
#endif
