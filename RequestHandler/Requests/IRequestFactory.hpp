/*
 * RequestFactory.hpp
 *
 *  Created on: Sep 18, 2020
 *      Author: zhukowych
 */

#ifndef REQUESTHANDLER_REQUESTS_IREQUESTFACTORY_HPP_
#define REQUESTHANDLER_REQUESTS_IREQUESTFACTORY_HPP_

#include "IRequest.hpp"

class IRequestFactory{
public:
	virtual ~IRequestFactory(){};
	virtual IRequest* CreateRequest(int RequestIddentiffer, int CommandIntIddentiffer, int ClientSocket) = 0;
};



#endif /* REQUESTHANDLER_REQUESTS_IREQUESTFACTORY_HPP_ */
