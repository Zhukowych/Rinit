/*
 * HNSW.cpp
 *
 *  Created on: Oct 13, 2020
 *      Author: zhukowych
 */

#include "HNSW.hpp"

HNSW::~HNSW(){
	vector<Layer*>::iterator it;
	for(it=Layers.begin(); it!=Layers.end();it++){
		delete (*it);
	}
}

void HNSW::operator=(const HNSW& copybable){
	Layers = copybable.Layers;
}

void HNSW::Insert(float* Query, int ID){
	CheckLayersSizeAndInsert(Query, ID);
}

void HNSW::CheckLayersSizeAndInsert(float* Query, int ID){
	if(Layers.size()>0){
		InsertToNotEmptyHNSW(Query, ID);
	}else{
		InsertToEmptyHNSW(Query, ID);
	}
}


void HNSW::InsertToNotEmptyHNSW(float* Query, int ID){
	Node* EnterNode = (Layers.back())->GetRandomNode();
	Node* NewNode = nullptr;
	Node* NodeOnUpperLevel = nullptr;
	Node* TopAddedNode = nullptr;
	vector<Node*> FoundNearestNeighbors;
	vector<Node*> Neighbors;
	vector<Node*> LayerNodes;
	vector<Node*>::iterator it;
	static int count = 1;
	int LevelOfTopLayer = Layers.size()-1;
	int LevelOfQuery = GetNewQueryLayerLevel();
	EnterNode = GetNearestElemenToQueryInLevel(Query, EnterNode, LevelOfQuery+1);
	cout << count << endl;
	count++;
	for (int Level=min(LevelOfTopLayer, LevelOfQuery); Level>=0; Level--){
		LayerNodes = Layers[Level]->GetNodes();
		FoundNearestNeighbors = Layers[Level]->SearchLayer(Query, EnterNode, NUM_OF_SEARCHING_CANDIDATES);
		if (Level==0){
			Neighbors = SelectNeighbors(Query, FoundNearestNeighbors, MAX_CONNECTIONS_ZERO_LEVEL);
			NewNode = Layers[Level]->AddNodeWithID(Query, ID);
		}else{
			Neighbors = SelectNeighbors(Query, FoundNearestNeighbors, MAX_CONNECTIONS);
			NewNode = Layers[Level]->AddNode(Query);
		}


		if(TopAddedNode==nullptr)TopAddedNode=NewNode;
		if(NodeOnUpperLevel!=nullptr)NodeOnUpperLevel->SetNodeOnPreviousLayer(NewNode);
		NodeOnUpperLevel = NewNode;
		for (it=Neighbors.begin(); it!=Neighbors.end();it++){
			if (Level==0){
				NewNode->AddBisirectionalConnections(*it, Query, MAX_CONNECTIONS_ZERO_LEVEL);
			}else{
				NewNode->AddBisirectionalConnections(*it, Query, MAX_CONNECTIONS);
			}
		}
		if(Level!=0)EnterNode = EnterNode->GetNodeOnPreviousLayer();

	}

	if(LevelOfQuery>LevelOfTopLayer){
		SetEnterPointOfHNSWFor(Query, ID)->SetNodeOnPreviousLayer(TopAddedNode);
	}

}

void HNSW::InsertToEmptyHNSW(float* Query, int ID){
	SetEnterPointOfHNSWFor(Query, ID);
}


Node* HNSW::SetEnterPointOfHNSWFor(float* Query, int ID){
	Layer* layer = new Layer();
	Node* NewNode;
	if (Layers.size()-1==0){
		NewNode = layer->AddNodeWithID(Query, ID);
	}else{
		NewNode = layer->AddNode(Query);
	}
	Layers.push_back(layer);
	return NewNode;
}


vector<NodeOnZeroLayer*> HNSW::KNNSearch(float* Query, int NumToReturn, int SizeOfCandidateList){
	Node* EnterNode = Layers.back()->GetRandomNode();
	vector<Node*> FoundNearestNeighbors;
	vector<NodeOnZeroLayer*> Result;
	int LevelOfTopLayer = Layers.size();
	EnterNode = GetNearestElemenToQueryInLevel(Query, EnterNode, 1);
	FoundNearestNeighbors = Layers[0]->SearchLayer(Query, EnterNode, SizeOfCandidateList);

	return ConvertNodeVector(FoundNearestNeighbors);
}

vector<NodeOnZeroLayer*> HNSW::ConvertNodeVector(const vector<Node*>& node_vector){
	vector<Node*>::const_iterator cit;
	vector<NodeOnZeroLayer*> result;
	for(cit=node_vector.begin(); cit!=node_vector.end();cit++){
		result.push_back(static_cast<NodeOnZeroLayer*>(*cit));
	}

	return result;
}

Node* HNSW::GetNearestElemenToQueryInLevel(float* Query, Node* EnterPoint, int MinLevel){
	vector<Node*> CandidatesNodes;
	for (int L = Layers.size()-1; L>=MinLevel;L--){
		CandidatesNodes = Layers[L]->SearchLayer(Query, EnterPoint, 1);
		EnterPoint = GetNearestToQueryFromVector(Query, CandidatesNodes);
		if(L!=0)EnterPoint = EnterPoint->GetNodeOnPreviousLayer();
	}

	return EnterPoint;
}


int HNSW::GetNewQueryLayerLevel(){
	std::random_device rd;
	std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
	int newLevel = int(-log(dis(gen))*Layers.size()*NORMALIZATION_FACTOR);
	if (newLevel>Layers.size()){
		return Layers.size();
	}else{
		return newLevel;
	}
}

vector<Node*> HNSW::SelectNeighbors(float* Query, vector<Node*>& Candidates, int NumToReturn){
	vector<Node*>::iterator it;
	if (Candidates.size()<NumToReturn)
		NumToReturn = Candidates.size();

	vector<Node*> NearestNodes(Candidates.begin(), Candidates.begin()+NumToReturn);
	vector<float> Distances(NumToReturn);
	float CurrentDistance = 0;
	float Smallest = 0;
	int SmallestInd = 0;


	for (int i=0; i<NumToReturn; i++){
		Distances[i] = Distance(Query, Candidates[i]->GetData());
	}

	for (it=Candidates.begin(); it!=Candidates.end(); it++){
		CurrentDistance = Distance(Query, (*it)->GetData());
		Smallest = Distances[0];
		for (int i=0; i<NumToReturn; i++){
			if (Distances[i]<Smallest ){
				Smallest = Distances[i];
				SmallestInd = i;
			}
		}
		if(CurrentDistance < Smallest && count(NearestNodes.begin(), NearestNodes.end(), *it)==0){
			Distances[SmallestInd] = CurrentDistance;
			NearestNodes[SmallestInd] = *it;
		}
	}

	return NearestNodes;
}

Node* HNSW::GetNearestToQueryFromVector(float* Query, vector<Node*>& Elements){
	vector<Node*>::iterator it;
	float NearestDistance = Distance(Query, (*Elements.begin())->GetData());
	float CurrentDistance;
	Node* CurrentNesrestNode = *Elements.begin();
	for (it=Elements.begin();it!=Elements.end(); it++){
		CurrentDistance = Distance(Query, (*it)->GetData());
		if (CurrentDistance<NearestDistance){
			NearestDistance = CurrentDistance;
			CurrentNesrestNode = *it;
		}
	}
	return CurrentNesrestNode;
}

void HNSW::ClearMemory(){
	vector<Layer*>::iterator it;
	for (it=Layers.begin(); it!=Layers.end(); it++)
		delete *it;
	Layers.clear();
}


// For Test

void HNSW::Check(){
	cout << "HJKL " << Layers.size() << endl;
}

int HNSW::GetLengthOfLayers(){
	return Layers.size();
}



