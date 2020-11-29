/*
 * NNLayer.cpp
 *
 *  Created on: Nov 12, 2020
 *      Author: zhukowych
 */

#include "NNLayer.hpp"

NNLayer::NNLayer() {
	// TODO Auto-generated constructor stub

}

NNLayer::NNLayer(int LayerSize, int NextLayerSize){
	weights = Matrix<float>(NextLayerSize, LayerSize);
}

NNLayer::NNLayer(int LayerSize){
	isOutputLayer = true;
}

Vector<float> NNLayer::InputToNextLayer(Vector<float> input){
	sigmoid(input);
	LayerValue = input;

	if(!isOutputLayer){
		return weights.dot(input);
	}else{
		return input;
	}
}
int NNLayer::size(){
	return LayerValue.size();
}

Vector<float> NNLayer::UpdateWeights(Vector<float> next_layer_delta){
	Vector<float> layer_delta = delta(next_layer_delta);
	if(!isOutputLayer){
		Matrix<float> weight_delta = different_length_dot(LayerValue, next_layer_delta);
		weights+= &weight_delta;
	}
	return layer_delta;
}

Vector<float> NNLayer::delta(Vector<float> input){
	if(isOutputLayer){
		return (LayerValue-input);
	}else{
		return weights.dot(input);
	}
}
Matrix<float> NNLayer::GetWeights(){
	return weights;
}

void NNLayer::sigmoid(Vector<float>& input){
	for(int i=0; i<input.size(); i++){
		input[i] = 1/(1+exp(-input[i]));

	}
}

