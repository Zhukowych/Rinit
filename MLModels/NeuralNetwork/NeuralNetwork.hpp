/*
 * NeuralNetwork.hpp
 *
 *  Created on: Nov 12, 2020
 *      Author: zhukowych
 */

#ifndef MLMODELS_NEURALNETWORK_NEURALNETWORK_HPP_
#define MLMODELS_NEURALNETWORK_NEURALNETWORK_HPP_
#include "../../Containers/Vector.hpp"
#include "NNLayer.hpp"
#include "NNStructure.hpp"
#include <iostream>

class NeuralNetwork {
public:
	NeuralNetwork();
	NeuralNetwork(Vector<int> LayerStructure);
	Vector<float> FeedForvard(Vector<float> data);
	void GradientStep(Vector<float> TrainInput, Vector<float> TrainOutput);
	NNStructure GetWeights();
private:
	NNLayer* layers;
	int Length;

	void FillLayers(Vector<int> LayerStructure);
};

#endif /* MLMODELS_NEURALNETWORK_NEURALNETWORK_HPP_ */
