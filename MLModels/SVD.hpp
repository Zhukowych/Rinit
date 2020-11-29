/*
 * SVD.hpp
 *
 *  Created on: Oct 31, 2020
 *      Author: zhukowych
 */

#ifndef MLMODELS_SVD_HPP_
#define MLMODELS_SVD_HPP_
#include "../Containers/DBMatrixResponse.hpp"
#include "../Containers/Matrix.hpp"
#include <map>


class SVD {
public:
	SVD(DBMatrixResponse<int>* data_);
	void Compute();

	Matrix<float>* GetUserMatrix();
	Matrix<float>* GetItemMatrix();

private:
	DBMatrixResponse<int>* data;
	Matrix<float>* UserMatrix;
	Matrix<float>* ItemMatrix;
	const int VectorLength = 10;
	const int NUM_EPOCHS = 1;
	const float LEARNING_RATE = 0.001f;
	const float LAMBDA = 0.15f;
	void CreateUserAndItemMatrix();
	void CreateUserAndItemIDToIndexMap(std::map<int, int>& UserIDToIndex, std::map<int, int>& ItemIDToIndex);
	void DoSGD();
	void ViewResults();
	inline void ProccesData();
	inline void UpdateVectors(int UserID, int ItemID, float rating);

};

#endif /* MLMODELS_SVD_HPP_ */
