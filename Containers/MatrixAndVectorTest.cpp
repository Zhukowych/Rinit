/*
 * MatrixAndVectorTest.cpp
 *
 *  Created on: Nov 1, 2020
 *      Author: zhukowych
 */

#include "Matrix.hpp"
#include <stdint.h>
#include <iostream>
#include <map>
using namespace std;

static const int VectorLength = 10;

void TestVectorMultiplication(){

	Vector<float> vector(VectorLength);
	Vector<float> multipled_vector = vector*2.0;

	for(int i=0; i<VectorLength; i++){
		if(multipled_vector[i]!=(vector[i]*2.0)){
			cout << "Vector Multipling is not valid" << endl;
			return;
		}
	}
}

void TestAddition(){
	float* LastVector2LastValues = new float[VectorLength];
	Vector<float> vector1(VectorLength);
	Vector<float> vector2(VectorLength);
	for(int i=0; i<VectorLength; i++){
		LastVector2LastValues[i] = vector2[i];
	}
	vector2+=vector1;

	for(int i=0; i<VectorLength; i++){
		if(LastVector2LastValues[i]+vector1[i]!=vector2[i]){
			cout << "Vector Addition is not valid" << endl;
			return;
		}
	}
}

void TestSubtraction(){
	Vector<float> vector1(VectorLength);
	Vector<float> vector2(VectorLength);
	Vector<float> subtracted = vector2-vector1;
	for(int i=0; i<VectorLength; i++){
		if(subtracted[i]!=(vector2[i]-vector1[i]))
			cout << "Vector subtraction is not valid" << endl;
	}
}

void TestMultipleOperations(){
	float* LastVector3LastValues = new float[VectorLength];
	Vector<float> vector1(VectorLength);
	Vector<float> vector2(VectorLength);
	Vector<float> vector3(VectorLength);
	for(int i=0; i<VectorLength; i++){
		LastVector3LastValues[i] = vector3[i];
	}
	vector3 += (vector2-vector1)*2.3f;
	for(int i=0; i<VectorLength; i++){
		cout << (vector2[i]-vector1[i])*2.3f << " " << vector3[i]-LastVector3LastValues[i] << endl;
	}
}

void VectorDotProductTest(){
	Vector<float> vector1(VectorLength);
	Vector<float> vector2(VectorLength);
	float dot_product = vector1.dot(vector2);
	float check_dot_product = 0;
	for(int i=0; i<VectorLength; i++){
		check_dot_product+=vector1[i]*vector2[i];
	}
	if(dot_product!=check_dot_product)
		cout << "Vector dot product not working" << endl;
}


void CreateIndexer(map<int, int>& indexer){
	int counter = 0;
	for (int i=1;i<6001;i++){
		indexer.insert(pair<int, int>(i, counter));
		counter++;
	}

}



void MatrixTest(){
	map<int, int> map1;
	CreateIndexer(map1);
	Matrix<float> matrix(map1, 6000, 10);
	Matrix<float>::indexer_iterator it;
	for(it=matrix.indexer_begin();it!=matrix.indexer_end();it++){
		cout << it->vector_->GetElements() << " " << it->ID << endl;
	}

}

int main(){
	TestVectorMultiplication();
	TestSubtraction();
	TestAddition();
	TestMultipleOperations();
	VectorDotProductTest();
	MatrixTest();
	return 0;
}

