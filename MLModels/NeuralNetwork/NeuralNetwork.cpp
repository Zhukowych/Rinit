/*
 * NeuralNetwork.cpp
 *
 *  Created on: Nov 12, 2020
 *      Author: zhukowych
 */

#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork() {
	// TODO Auto-generated constructor stub

}

NeuralNetwork::NeuralNetwork(Vector<int> LayerStructure) {
	layers = new NNLayer[LayerStructure.size()];
	Length = LayerStructure.size();
	FillLayers(LayerStructure);
}

void NeuralNetwork::FillLayers(Vector<int> LayerStructure){
	for (int i=0; i<LayerStructure.size(); i++){
		if(i==LayerStructure.size()-1)
			layers[i] = NNLayer(LayerStructure[i]);
		else
			layers[i] = NNLayer(LayerStructure[i], LayerStructure[i+1]);
	}
}

Vector<float> NeuralNetwork::FeedForvard(Vector<float> data){
	Vector<float> output;
	for(int i=0; i<Length; i++){
		if(i==0){
			output = layers[i].InputToNextLayer(data);
		}else{
			output = layers[i].InputToNextLayer(output);
		}
	}
	return output;
}

void NeuralNetwork::GradientStep(Vector<float> TrainInput, Vector<float> TrainOutput){
	Vector<float> delta;
	FeedForvard(TrainInput);
	for(int i=Length-1; i>0; i--){
		if(i==Length-1){
			delta = layers[i].UpdateWeights(TrainOutput);
		}else{
			delta = layers[i].UpdateWeights(delta);
		}
	}
}

NNStructure NeuralNetwork::GetWeights(){
	NNStructure nn_structure(Length);
	for(int i=0; i<Length; i++){
		nn_structure[i] = layers[i].GetWeights();
	}
	return nn_structure;
}
