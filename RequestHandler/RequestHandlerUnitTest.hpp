/*
 * RequesdtHandlerUnitTest.hpp
 *
 *  Created on: Sep 11, 2020
 *      Author: zhukowych
 */

#ifndef REQUESTHANDLER_REQUESTHANDLERUNITTEST_HPP_
#define REQUESTHANDLER_REQUESTHANDLERUNITTEST_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include "RequestHandler.hpp"
#include "IRequestHandler.hpp"
using namespace std;

class RequestHandlerUnitTest{
public:
	RequestHandlerUnitTest();
	~RequestHandlerUnitTest();
	void Test();
private:
	const int CLIENT_SOCKET = 1;
	const char* COMMAND = "12111111";
	void TestObjectCreation();
	void TestHandleRequest();
	IRequestHandler* CreateRequestHandler(const char* Command, int ClientSocket);
};


#endif /* REQUESTHANDLER_REQUESTHANDLERUNITTEST_HPP_ */
