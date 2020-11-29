#include "ServerUnitTest.hpp"

void ServerUnitTest::Test(){
	client.Connect();
	client.SendCommand(COMMAND);
	client.WaitForClose();
}

void ServerClient::Connect(){
	CreateSocket();
	SetServerAdderss();
	SetInetPton();
	ConnectToServer();
}

void ServerClient::CreateSocket(){
	if ((ClientSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("Socket creation error \n");
		exit(EXIT_FAILURE);
	}
}

void ServerClient::SetServerAdderss(){
	ServerAddress.sin_family = AF_INET;
	ServerAddress.sin_port = htons(PORT);
}

void ServerClient::SetInetPton(){
	if(inet_pton(AF_INET, "127.0.0.1", &ServerAddress.sin_addr)<=0)
	{
		printf("Invalid address/ Address not supported \n");
		exit(EXIT_FAILURE);
	}
}

void ServerClient::ConnectToServer(){
    if (connect(ClientSocket, (struct sockaddr *)&ServerAddress, sizeof(ServerAddress)) < 0)
    {
        printf("\nConnection Failed \n");
		exit(EXIT_FAILURE);
    }
}

void ServerClient::SendCommand(const char* messange){
	send(ClientSocket, messange , strlen(messange), 0 );
}

void ServerClient::WaitForClose(){
	char buffer[3]  ={0};
	int bytes = read( ClientSocket, buffer, 3);
}
