/*
 * RequestFactory.cpp
 *
 *  Created on: Sep 18, 2020
 *      Author: zhukowych
 */

#include "RequestFactory.hpp"

IRequest* RequestFactory::CreateRequest(int RequestIdentiffer, int CommandIntIddentiffer, int ClientSocket){
	switch(RequestIdentiffer){
		case GET_RECCOMENDATIONS:
			return new GetReccomendationsRequest(CommandIntIddentiffer, ClientSocket);
		break;
		case TRAIN_MODELS:
			return new TrainReccomenderModels(CommandIntIddentiffer, ClientSocket);
		break;
	}
}
