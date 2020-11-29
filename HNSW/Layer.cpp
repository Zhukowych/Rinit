/*
 * Layer.cpp
 *
 *  Created on: Oct 13, 2020
 *      Author: zhukowych
 */
#include "Layer.hpp"



Layer::~Layer(){
	vector<Node*>::iterator it;

	for (it = Nodes.begin(); it!=Nodes.end();it++){
		delete (*it);
	}
}

Node* Layer::GetRandomNode(){
	return Nodes[rand()%Nodes.size()];
}

Node* Layer::AddNode(float* Data){
	Node* newNode = new Node(Data);
	Nodes.push_back(newNode);
	return newNode;
}

Node* Layer::AddNodeWithID(float* Data, int ID){
	Node* newNode = new NodeOnZeroLayer(Data, ID);
	Nodes.push_back(newNode);
	return newNode;
}

Node* Layer::GetLastNode(){
	return (*(Nodes.end()));
}

int Layer::GetSize(){
	return Nodes.size();
}

vector<Node*> Layer::SearchLayer(float* Query, Node* EnterNode, int NumToReturn){
	int LastSize = 0;
	set<Node*> VisitedElements = {EnterNode};
	priority_queue<Node*> CandidatesElements;
	priority_queue<Node*> FountNearestNeighbors;
	vector<Node*> Neighborhoods;
	vector<Node*> Result;
	vector<Node*>::iterator it;
	set<Node*>::iterator its;
	Node* NerestFromCantidates;
	Node* LastNearest;
	Node* FurthestFromFoundNN;
	CandidatesElements.push(EnterNode);
	FountNearestNeighbors.push(EnterNode);

	while (CandidatesElements.size()){
		NerestFromCantidates = CandidatesElements.top();
		FurthestFromFoundNN = FountNearestNeighbors.top();

		if(CheckFindingAllNN(Query, NerestFromCantidates, FurthestFromFoundNN, NumToReturn, FountNearestNeighbors.size()	)) break;
		CandidatesElements.pop();
		Neighborhoods = NerestFromCantidates->GetNeighbourhood();
		for (it=Neighborhoods.begin(); it<Neighborhoods.end(); it++){
			if(VisitedElements.count(*it)==0){
				VisitedElements.insert((*it));
				FurthestFromFoundNN = FountNearestNeighbors.top();
				if(CheckIfSmalestDistance(*it, FurthestFromFoundNN, Query) || FountNearestNeighbors.size() < NumToReturn){
					CandidatesElements.push(*it);
					FountNearestNeighbors.push(*it);
					if (FountNearestNeighbors.size()>NumToReturn) FountNearestNeighbors.pop();
				}

			}
		}

		// End While
	}

	while(!FountNearestNeighbors.empty()){
		Result.push_back(FountNearestNeighbors.top());
		FountNearestNeighbors.pop();

	}
	return Result;
}

vector<Node*> Layer::GetNodes(){
	return Nodes;
}

inline bool Layer::CheckFindingAllNN(float* Query, Node* Nearest, Node* Furthest, int NumToReturn, int Found){
	if(Distance(Query, Nearest->GetData())>Distance(Query, Furthest->GetData()) && Found >=NumToReturn ){
		return true;
	}else{
		return false;
	}
}

inline bool Layer::CheckIfSmalestDistance(Node* Element, Node* Furthest, float* Query){
	if(Distance(Element->GetData(), Query) < Distance(Furthest->GetData(), Query)){
		return true;
	}else{
		return false;
	}
}



