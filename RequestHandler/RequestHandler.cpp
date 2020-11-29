/*
 * RequestHandler.cpp
 *
 *  Created on: Sep 12, 2020
 *      Author: zhukowych
 */

#include "RequestHandler.hpp"

void RequestHandler::Handle(){
	std::thread HandleThread(&RequestHandler::CreateResponse, this);
	HandleThread.detach();
}

void RequestHandler::CreateResponse(){
	SplitCommandToRequestAndIntIddentiffers();
	IRequest* request = Factory->CreateRequest(RequestIddentiffer, CommandIntIddentiffer, ClientSocket);
	request->Execute();
	delete request;
	delete this;
}

void RequestHandler::SplitCommandToRequestAndIntIddentiffers(){
	char RequestCharIddentiffer[REQUEST_IDDENTIFFER_LENGTH] = {Command[0], Command[1]};
	char CommandCharIddentiffer[COMMAND_INT_IDDENTIFFER_LENGT] = {0};
	for (int i=2; i<COMMAND_LENGTH; i++){
		CommandCharIddentiffer[i-REQUEST_IDDENTIFFER_LENGTH] = Command[i];
	}
	RequestIddentiffer = atoi(RequestCharIddentiffer);
	CommandIntIddentiffer = atoi(CommandCharIddentiffer);
}
