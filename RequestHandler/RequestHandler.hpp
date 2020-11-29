/*
 * RequestHandler.hpp
 *
 *  Created on: Sep 11, 2020
 *      Author: zhukowych
 */

#ifndef REQUESTHANDLER_REQUESTHANDLER_HPP_
#define REQUESTHANDLER_REQUESTHANDLER_HPP_

#include "IRequestHandler.hpp"
#include "Requests/IRequest.hpp"
#include <thread>

class RequestHandler: public IRequestHandler{
public:
	RequestHandler(const char* Command, int ClientSocket):IRequestHandler(Command, ClientSocket){};
	void Handle();
private:
	void CreateResponse();
	void SplitCommandToRequestAndIntIddentiffers();
};



#endif /* REQUESTHANDLER_REQUESTHANDLER_HPP_ */
