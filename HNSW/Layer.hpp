/*
 * Layer.hpp
 *
 *  Created on: Oct 4, 2020
 *      Author: zhukowych
 */

#ifndef HNSW_LAYER_HPP_
#define HNSW_LAYER_HPP_

#include <algorithm>
#include <stdlib.h>
#include<set>
#include<queue>
#include "Node.hpp"
#include "NodeOnZeroLayer.h"
#include "Utils.hpp"

static set<Node*> nodes;
class Layer{
public:
	~Layer();
	Node* GetRandomNode();
	vector<Node*> SearchLayer(float* Query, Node* EnterNode, int NumToReturn);
	Node* AddNode(float* Data);
	Node* AddNodeWithID(float* Data, int ID);
	Node* GetLastNode();
	vector<Node*> GetNodes();
	int GetSize();
private:
	vector<Node*> Nodes;


	//Util functions
	Node* GetNearest(float* Query, set<Node*>& Elements, Node* LastNearest, bool& IsInLocalMinimum, int NumToReturn, int FoundSize, set<Node*>& Visited);

	inline bool CheckFindingAllNN(float* Query, Node* Nearest, Node* Furthest, int NumToReturn, int Found);
	inline bool CheckIfSmalestDistance(Node* Element, Node* Furthest, float* Query);


};



#endif /* HNSW_LAYER_HPP_ */
