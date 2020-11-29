/*
 * IRequestHandler.hpp
 *
 *  Created on: Sep 11, 2020
 *      Author: zhukowych
 */

#ifndef REQUESTHANDLER_IREQUESTHANDLER_HPP_
#define REQUESTHANDLER_IREQUESTHANDLER_HPP_

#include "Requests/IRequestFactory.hpp"
#include "Requests/RequestFactory.hpp"

class IRequestHandler{
public:
	IRequestHandler(const char* Command_, int ClientSocket_){
		Command = Command_; ClientSocket = ClientSocket_;
	};
	virtual ~IRequestHandler(){delete Factory;};
	virtual void Handle()=0;
protected:
	const char* Command;
	const int REQUEST_IDDENTIFFER_LENGTH = 2;
	const int COMMAND_INT_IDDENTIFFER_LENGT = 6;
	const int COMMAND_LENGTH = 8;
	int RequestIddentiffer;
	int CommandIntIddentiffer;
	int ClientSocket;
	IRequestFactory* Factory = new RequestFactory;

};

#endif /* REQUESTHANDLER_IREQUESTHANDLER_HPP_ */
