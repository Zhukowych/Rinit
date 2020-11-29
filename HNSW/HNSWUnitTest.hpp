/*
 * HNSWUnitTest.hpp
 *
 *  Created on: Oct 4, 2020
 *      Author: zhukowych
 */

#ifndef HNSW_HNSWUNITTEST_HPP_
#define HNSW_HNSWUNITTEST_HPP_
#include "HNSW.hpp"
#include<iostream>
#include<vector>
#include<chrono>
#include<random>
#include<unistd.h>
#include "NodeOnZeroLayer.h"
using namespace std;

class HNSWUnitTest {
public:
	void Test();
private:
	vector<float*> RandomVector;
	HNSW hnsw;
	const int NumOfArrays = 6000;
	int ID = 1;

	void CreateRandomFloatArray();
	void TestInsert();
	void TestSearch();
};

#endif /* HNSW_HNSWUNITTEST_HPP_ */
