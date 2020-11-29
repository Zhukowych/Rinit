/*
 * NeighborVectorTest.cpp
 *
 *  Created on: Oct 29, 2020
 *      Author: zhukowych
 */


#include "NeighborVector.hpp"
#include <iostream>
using namespace std;
class Node{};

const int vector_size = 6;
int main(){
	NeighborVector<Node*> v(vector_size);
	NeighborVector<Node*> v1(vector_size);
	NeighborVector<Node*>::iterator it;
	Node* TestPointer;
	for (int i=0; i<vector_size;i++){
		TestPointer = new Node;
		cout << TestPointer << endl;
		v.push(TestPointer);
	}
	for(it=v.begin(); it!=v.end();++it){
		cout << 1 << endl;
		cout << *it << endl;
	}
	cout << sizeof(v) << endl;
	cout << sizeof(it) << endl;
	v = v1;
	return 0;
}

