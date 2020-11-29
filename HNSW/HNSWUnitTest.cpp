/*
 * HNSWUnitTest.cpp
 *
 *  Created on: Oct 4, 2020
 *      Author: zhukowych
 */

#include "HNSWUnitTest.hpp"

void HNSWUnitTest::Test(){
	CreateRandomFloatArray();
	TestInsert();
	TestSearch();
	cout << "345 " << getpid() << endl;
	cout << sizeof(vector<Node*>) << endl;
	while(1){}
	//hnsw.Check();
}

void HNSWUnitTest::TestInsert(){
	for (int i=0; i<RandomVector.size(); i++){
		hnsw.Insert(RandomVector[i], ID);
		ID++;
	}
	cout << "End inserting" << endl;
}

void HNSWUnitTest::CreateRandomFloatArray(){
	std::random_device rd;
	std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 10.0);
	float* RandomArray;
	for (int i=0; i<NumOfArrays; i++){
		RandomArray = new float[10];
		for(int j=0; j<10;j++){
			RandomArray[j] =dis(gen);
		}
		RandomVector.push_back(RandomArray);
	}
	cout << "End Creating Random arrays" << endl;

}

void HNSWUnitTest::TestSearch(){
	auto start = chrono::high_resolution_clock::now();
	NodeOnZeroLayer* z;
	vector<Node*>::iterator it;
	vector<NodeOnZeroLayer*> result = hnsw.KNNSearch(RandomVector[0], 100, 100);
	auto end= chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end-start).count();
}
