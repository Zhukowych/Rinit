/*
 * Node.cpp
 *
 *  Created on: Oct 13, 2020
 *      Author: zhukowych
 */
#include "Node.hpp"


Node::Node(float* Data_){
	Data = Data_;
}

Node::~Node(){

}
void Node::SetNodeOnPreviousLayer(Node* node){
	NodeOnPreviousLayer = node;
}


void Node::AddBisirectionalConnections(Node* Neighbor, float* Query, int MaxConnections){
	AddNodeToNeighbors(Neighbor, Query, MaxConnections);
	Neighbor->AddNodeToNeighbors(this, Query, MaxConnections);
}

void Node::AddNodeToNeighbors(Node* Neighbor, float* Query, int MaxConnections){
	vector<Node*>::iterator it;
	vector<Node*>::iterator result;
	int SmallestInd;
	float SmallestDistance = 1000;
	float CurrentDistance = 0;
	float* NewNeighborData = Neighbor->GetData();

	if(Neighbourhood.size()<MaxConnections){
		Neighbourhood.push_back(Neighbor);
		return;
	}else{
		Neighbourhood.push_back(Neighbor);
		UpdateNeighbors(MaxConnections);
	}
}

void Node::UpdateNeighbors(int MaxConnections){
	vector<Node*> NewNeighbors;
	vector<Node*> Candidates(Neighbourhood.begin(), Neighbourhood.end());
	vector<Node*> CandidateNeighbors;
	vector<Node*> DiscardedNodes;
	vector<Node*>::iterator it;
	vector<Node*>::iterator nit;
	Node* CurrentComparingNeighbor;
	for(it=Neighbourhood.begin();it!=Neighbourhood.end();it++){
		CandidateNeighbors = (*it)->GetNeighbourhood();
		for(nit=CandidateNeighbors.begin();nit!=CandidateNeighbors.end();nit++){
			if(!count(Candidates.begin(), Candidates.end(), *nit)){
				Candidates.push_back(*nit);
			}
		}
	}

	while(Candidates.size() && NewNeighbors.size()<=MaxConnections){
		CurrentComparingNeighbor = Candidates.back();
		if (IfCloserToDataComparedWith(CurrentComparingNeighbor, NewNeighbors)){
			NewNeighbors.push_back(CurrentComparingNeighbor);
		}else{
			DiscardedNodes.push_back(CurrentComparingNeighbor);
		}
		Candidates.pop_back();
	}

	while(NewNeighbors.size()<=MaxConnections){
		CurrentComparingNeighbor = DiscardedNodes.back();
		NewNeighbors.push_back(CurrentComparingNeighbor);
		DiscardedNodes.pop_back();
	}
	Neighbourhood = NewNeighbors;
}

inline bool Node::IfCloserToDataComparedWith(Node* ComparableNode, vector<Node*>& ComparableVector){
	vector<Node*>::iterator it;
	float ComparableNodeDisrance = Distance(ComparableNode->GetData(), Data);
	if (!ComparableVector.size())return true;
	for(it=ComparableVector.begin(); it!=ComparableVector.end();it++){
		if(ComparableNodeDisrance<Distance((*it)->GetData(), Data)){
			return true;
		}
	}
	return false;
}

vector<Node*>& Node::GetNeighbourhood(){
	return Neighbourhood;
}

Node* Node::GetNodeOnPreviousLayer(){
	return NodeOnPreviousLayer;
}


float* Node::GetData(){
	return Data;
}
