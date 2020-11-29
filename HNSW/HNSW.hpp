/*
 * HNSW.hpp
 *
 *  Created on: Oct 4, 2020
 *      Author: zhukowych
 */

#ifndef HNSW_HNSW_HPP_
#define HNSW_HNSW_HPP_
#include "Layer.hpp"
#include<algorithm>
#include <random>


class HNSW{
private:
	vector<Layer*> Layers;
	void CheckLayersSizeAndInsert(float* Query, int ID);
	void InsertToEmptyHNSW(float* Query, int ID);
	void InsertToNotEmptyHNSW(float* Query, int ID);
	Node* SetEnterPointOfHNSWFor(float* Query, int ID);

	int GetNewQueryLayerLevel();

	Node* GetNearestElemenToQueryInLevel(float* Query, Node* EnterPoint, int MinLevel);
	Node* GetNearestToQueryFromVector(float* Query, vector<Node*>& Elements);
	vector<Node*> SelectNeighbors(float* Query, vector<Node*>& Candidates, int NumToReturn);
	vector<NodeOnZeroLayer*> ConvertNodeVector(const vector<Node*>& node_vector);

	const float NORMALIZATION_FACTOR = 0.15;
	const int NUM_OF_SEARCHING_CANDIDATES = 20;
	const int MAX_CONNECTIONS = 3;
	const int MAX_CONNECTIONS_ZERO_LEVEL = 10;

	int Count =0;
public:
	~HNSW();

	void Insert(float* Query, int ID);
	vector<NodeOnZeroLayer*> KNNSearch(float* Query, int NumToReturn, int SizeOfCandidateList);
	void operator=(const HNSW& copybable);
	void ClearMemory();
	void Check();

	// For Test
	int GetLengthOfLayers();
};




#endif /* HNSW_HNSW_HPP_ */
