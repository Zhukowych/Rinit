/*
 * RequestHandlerUnitTest.cpp
 *
 *  Created on: Sep 11, 2020
 *      Author: zhukowych
 */
#include "RequestHandlerUnitTest.hpp"

RequestHandlerUnitTest::RequestHandlerUnitTest(){

}

RequestHandlerUnitTest::~RequestHandlerUnitTest(){

}

void RequestHandlerUnitTest::Test(){
	TestHandleRequest();
}

void RequestHandlerUnitTest::TestHandleRequest(){
	IRequestHandler* handler = CreateRequestHandler(COMMAND, CLIENT_SOCKET);
	handler->Handle();
	this_thread::sleep_for(2s);
	ifstream testfile ("test.txt");
	string line;
	if(!getline(testfile, line)){
		cout << "Test failed" << endl;
	}
	while(getline(testfile, line)){
		if (line=="train"){
			break;
		}else{
			cout << "Test Failed" << endl;
		}
	}
	testfile.close();
}

IRequestHandler* RequestHandlerUnitTest::CreateRequestHandler(const char* Command, int ClientSocket){
	return new RequestHandler(Command, ClientSocket);
}
