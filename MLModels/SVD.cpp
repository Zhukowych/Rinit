/*
 * SVD.cpp
 *
 *  Created on: Oct 31, 2020
 *      Author: zhukowych
 */

#include "SVD.hpp"

SVD::SVD(DBMatrixResponse<int>* data_) {
	data = data_;
}

void SVD::Compute(){
	CreateUserAndItemMatrix();
	DoSGD();
}


Matrix<float>* SVD::GetUserMatrix(){
	return UserMatrix;
}

Matrix<float>* SVD::GetItemMatrix(){
	return ItemMatrix;
}

void SVD::ViewResults(){
	Matrix<float>::iterator it;
	for(it=UserMatrix->begin();it!=UserMatrix->end();it++){
		cout << (*it)[0] << endl;
	}
}

void SVD::CreateUserAndItemMatrix(){
	std::map<int, int> UserIDToIndex, ItemIDToIndex;
	CreateUserAndItemIDToIndexMap(UserIDToIndex, ItemIDToIndex);
	UserMatrix = new Matrix<float>(UserIDToIndex, UserIDToIndex.size(), VectorLength);
	ItemMatrix = new Matrix<float>(ItemIDToIndex, ItemIDToIndex.size(), VectorLength);
}

void SVD::CreateUserAndItemIDToIndexMap(std::map<int, int>& UserIDToIndex, std::map<int, int>& ItemIDToIndex){
	DBMatrixResponse<int>::iterator it;
	int IndexUserID = 0;
	int IndexItemID = 0;
	for(it=data->begin();it!=data->end(); it++){
		if(!UserIDToIndex.count((*it)[0])){
			UserIDToIndex.insert(std::pair<int, int>((*it)[0], IndexUserID));
			IndexUserID++;
		}
		if(!ItemIDToIndex.count((*it)[1])){
			ItemIDToIndex.insert(std::pair<int, int>((*it)[1], IndexUserID));
			IndexItemID++;
		}
	}
}

void SVD::DoSGD(){
	for(int i=0; i<NUM_EPOCHS; i++){
		//ProccesData();
	}
}

inline void SVD::ProccesData(){
	DBMatrixResponse<int>::iterator it;
	for(it=data->begin();it!=data->end(); it++){
		//UpdateVectors((*it)[0], (*it)[1], (*it)[2]);
	}
}

inline void SVD::UpdateVectors(int UserID, int ItemID, float rating){
	Vector<float>& UserVector = (*UserMatrix)[UserID];
	Vector<float>& ItemVector  = (*ItemMatrix)[ItemID];
	float error = rating - UserVector.dot(ItemVector);
	UserVector += (ItemVector*error-UserVector*LAMBDA)*LEARNING_RATE;
	ItemVector += (UserVector*error-ItemVector*LAMBDA)*LEARNING_RATE;
}


