/*
 * SVDModelTest.cpp
 *
 *  Created on: Nov 6, 2020
 *      Author: zhukowych
 */

#include "SVDModelTest.hpp"




SVDModelTest::SVDModelTest(SVD* svd_) {
	svd = svd_;
	UserMatrix = svd->GetUserMatrix();
	ItemMatrix = svd->GetItemMatrix();

	UsersTestReccomendations = new Matrix<unsigned int>(UserMatrix->size(), LENGTH_OF_RECOMENDER_VECTOR);
}

void SVDModelTest::Test(){
	InsertIntoHNSW();
	CreateReccomenderMatrix();
	InsertResults();
}

void SVDModelTest::InsertIntoHNSW(){
	Matrix<float>::indexer_iterator it;
	for(it=ItemMatrix->indexer_begin();it!=ItemMatrix->indexer_end();it++){
		TestHNSW.Insert(it->vector_->GetElements(), it->ID);
	}
}

void SVDModelTest::CreateReccomenderMatrix(){
	Matrix<float>::indexer_iterator it;
	Matrix<unsigned int>::iterator sit;
	for(it=UserMatrix->indexer_begin(), sit=UsersTestReccomendations->begin();it!=UserMatrix->indexer_end(), sit!=UsersTestReccomendations->end();it++, sit++){
		*sit = CreateReccomenderVector(it);
	}
}

Vector<unsigned int> SVDModelTest::CreateReccomenderVector(Matrix<float>::indexer_iterator it){
	vector<NodeOnZeroLayer*> NearestNeighbors = TestHNSW.KNNSearch(it->vector_->GetElements(), NUM_OF_SEARCHING_NEIGHBORS, NUM_OF_SEARCHING_CANDIDATES);
	Vector<unsigned int> Result(LENGTH_OF_RECOMENDER_VECTOR);
	for(int i=0; i<LENGTH_OF_RECOMENDER_VECTOR; i++){
		if(i==0){
			Result[i] = it->ID;
		}else{
			Result[i] = NearestNeighbors[i-1]->GetID();
		}
	}
	return Result;
}

void SVDModelTest::InsertResults(){
	MYSQLDataBase db;
	db.Connect();
	db.InsertTestReccomendations(UsersTestReccomendations);
	db.Disconnect();
}
