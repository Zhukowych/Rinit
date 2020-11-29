/*
 * NodeOnZeroLayer.h
 *
 *  Created on: Nov 5, 2020
 *      Author: zhukowych
 */

#ifndef HNSW_NODEONZEROLAYER_H_
#define HNSW_NODEONZEROLAYER_H_
#include "Node.hpp"

class NodeOnZeroLayer : public Node{
public:
	NodeOnZeroLayer(float* Data_, int ID_):Node(Data_){ID=ID_;};
	int GetID(){return ID;};
private:
	int ID;
};

#endif /* HNSW_NODEONZEROLAYER_H_ */
