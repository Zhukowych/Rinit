/*
 * Layer.hpp
 *
 *  Created on: Nov 12, 2020
 *      Author: zhukowych
 */

#ifndef MLMODELS_NEURALNETWORK_NNLAYER_HPP_
#define MLMODELS_NEURALNETWORK_NNLAYER_HPP_
#include "../../Containers/Matrix.hpp"
#include <cmath>

class NNLayer {
public:
	NNLayer();
	NNLayer(int LayerSize, int NextLaterSize);
	NNLayer(int LayerSize);
	Vector<float> InputToNextLayer(Vector<float> input);
	Vector<float> delta(Vector<float> input);
	Vector<float> UpdateWeights(Vector<float> next_layer_delta);
	Matrix<float> GetWeights();
	int size();
private:
	Matrix<float> weights;
	Vector<float> LayerValue;
	bool isOutputLayer = false;
	float LEARNING_RATE = 0.3f;

	void sigmoid(Vector<float>& input);
};

#endif /* MLMODELS_NEURALNETWORK_NNLAYER_HPP_ */
