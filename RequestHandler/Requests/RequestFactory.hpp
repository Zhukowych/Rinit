/*
 * RequestFactory.h
 *
 *  Created on: Sep 18, 2020
 *      Author: zhukowych
 */

#ifndef REQUESTHANDLER_REQUESTS_REQUESTFACTORY_HPP_
#define REQUESTHANDLER_REQUESTS_REQUESTFACTORY_HPP_

#include "IRequestFactory.hpp"
#include "Requests.hpp"

enum REQUESTS_TYPES {
	GET_RECCOMENDATIONS = 11,
	TRAIN_MODELS = 12,
};
class RequestFactory : public IRequestFactory{
public:
	RequestFactory(){};
	IRequest* CreateRequest(int RequestIddentiffer, int CommandIntIddentiffer, int ClientSocket) override;
};

#endif /* REQUESTHANDLER_REQUESTS_REQUESTFACTORY_HPP_ */
