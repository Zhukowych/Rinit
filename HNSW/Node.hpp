/*
 * Node.hpp
 *
 *  Created on: Oct 4, 2020
 *      Author: zhukowych
 */

#ifndef HNSW_NODE_HPP_
#define HNSW_NODE_HPP_

#include<vector>
#include<iostream>
#include "math.h"
#include "Utils.hpp"
#include <algorithm>
#include <algorithm>
#include "../Containers/NeighborVector.hpp"
using namespace std;



class Node{
public:
	Node(float* Data_);
	~Node();
	void SetNodeOnPreviousLayer(Node* node);
	void AddBisirectionalConnections(Node* Neighbor, float* Query, int MaxConnections);
	void AddNodeToNeighbors(Node* Neighbor, float* Query, int MaxConnections);
	float* GetData();
	vector<Node*>& GetNeighbourhood();
	Node* GetNodeOnPreviousLayer();
private:
	float* Data;
	Node* NodeOnPreviousLayer = nullptr;
	vector<Node*> Neighbourhood;

	void UpdateNeighbors(int MaxConnections);
	inline  bool IfCloserToDataComparedWith(Node* ComparableNode, vector<Node*>& ComparableVector);
};


#endif /* HNSW_NODE_HPP_ */
