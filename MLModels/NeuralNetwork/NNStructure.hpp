/*
 * NNStructutre.hpp
 *
 *  Created on: Nov 15, 2020
 *      Author: zhukowych
 */

#ifndef MLMODELS_NEURALNETWORK_NNSTRUCTURE_HPP_
#define MLMODELS_NEURALNETWORK_NNSTRUCTURE_HPP_

#include "../../Containers/Matrix.hpp"

class NNStructure {
public:
	NNStructure(int size_);
	Matrix<float>& operator[](int index);
private:
	int size;
	Matrix<float>* weights;
};

NNStructure::NNStructure(int size_){
	size = size_;
	weights = new Matrix<float>[size];
}

Matrix<float>& NNStructure::operator[](int index){
	if(index>size) throw std::runtime_error("NNStructure index error");
	return weights[index];
}


#endif /* MLMODELS_NEURALNETWORK_NNSTRUCTURE_HPP_ */
