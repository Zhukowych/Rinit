/*
 * IRequest.hpp
 *
 *  Created on: Sep 18, 2020
 *      Author: zhukowych
 */

#ifndef REQUESTHANDLER_REQUESTS_IREQUEST_HPP_
#define REQUESTHANDLER_REQUESTS_IREQUEST_HPP_


class IRequest{
public:
	IRequest(int CommandIntIddentiffer_, int ClientSocket_){
		CommandIntIddentiffer = CommandIntIddentiffer_; ClientSocket = ClientSocket_;
	};
	virtual ~IRequest(){}
	virtual void Execute() = 0;
protected:
	int CommandIntIddentiffer, ClientSocket;

};


#endif /* REQUESTHANDLER_REQUESTS_IREQUEST_HPP_ */
