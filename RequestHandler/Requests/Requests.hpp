/*
 * Requests.hpp
 *
 *  Created on: Sep 18, 2020
 *      Author: zhukowych
 */

#ifndef REQUESTHANDLER_REQUESTS_REQUESTS_HPP_
#define REQUESTHANDLER_REQUESTS_REQUESTS_HPP_

#include "IRequest.hpp"
#include <iostream>
#include <unistd.h>
#include "../../DataBase/DataBase.hpp"
#include "../../Containers/DBMatrixResponse.hpp"
#include "../../MLModels/SVD.hpp"
#include "../../Tests/SVDModelTest.hpp"
#include "GlobalSettings.hpp"
#include <malloc.h>
using namespace std;

class GetReccomendationsRequest : public IRequest{
public:
	GetReccomendationsRequest(int CommandIntIddentiffer_, int ClientSocket_): IRequest(CommandIntIddentiffer_, ClientSocket_){};
	void Execute() override;
private:
	MYSQLDataBase DataBase;
	Vector<float> UserVector;

	void ConnectToDBAndGetData();
};

class TrainReccomenderModels : public IRequest{
public:
	TrainReccomenderModels(int CommandIntIddentiffer_, int ClientSocket_): IRequest(CommandIntIddentiffer_, ClientSocket_){};
	void Execute() override;
private:
	MYSQLDataBase DataBase;
	DBMatrixResponse<int>* response;
	SVD* SVDModel;
	SVDModelTest* Test;

	Matrix<float>* UserMatrix;
	Matrix<float>* ItemMatrix;


	void TrainMLModels();
	void ExportData();
	//ML
	void TrainSVDModel();

	//DATA
	void ConnectToDBAndGetData();
	void AddItemVectorsToHNSW();
	void AddUserVectorsToDB();
	void ClearMemory();


};



#endif /* REQUESTHANDLER_REQUESTS_REQUESTS_HPP_ */
