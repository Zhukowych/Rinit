/*
 * SVDModelTest.h
 *
 *  Created on: Nov 6, 2020
 *      Author: zhukowych
 */

#ifndef TESTS_SVDMODELTEST_HPP_
#define TESTS_SVDMODELTEST_HPP_
#include "../MLModels/SVD.hpp"
#include "../HNSW/HNSW.hpp"
#include "../Containers/Matrix.hpp"
#include "../DataBase/DataBase.hpp"
#include <vector>
using namespace std;

class SVDModelTest {
public:
	SVDModelTest(SVD* svd_);
	void Test();
private:
	SVD* svd;
	HNSW TestHNSW;
	Matrix<float>* UserMatrix;
	Matrix<float>* ItemMatrix;
	Matrix<unsigned int>* UsersTestReccomendations;
	const int NUM_OF_SEARCHING_NEIGHBORS = 10;
	const int NUM_OF_SEARCHING_CANDIDATES = 20;
	const int LENGTH_OF_RECOMENDER_VECTOR = 11;

	void InsertIntoHNSW();
	void CreateReccomenderMatrix();
	Vector<unsigned int> CreateReccomenderVector(Matrix<float>::indexer_iterator it);
	void InsertResults();
};

#endif /* TESTS_SVDMODELTEST_HPP_ */
