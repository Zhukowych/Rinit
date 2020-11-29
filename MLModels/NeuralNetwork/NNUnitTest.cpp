#include "NeuralNetwork.hpp"
#include "../../Containers/Vector.hpp"


Vector<int> CreateNNStructure(){
	Vector<int> result(3);
	result[0] = 5;
	result[1] = 3;
	result[2] = 2;
	return result;
}

Vector<float> CreateTrainData(){
	Vector<float> result(2);
	result[0] = 1;
	result[1] = 1;
	return result;
}
Vector<float> CreateData(){
	Vector<float> result(5);
	for(int i=0; i<5; i++){
		result[i] = i;
	}
	return result;
}

void Test(){
	NeuralNetwork NN(CreateNNStructure());
	Vector<float> output =NN.FeedForvard(CreateData());
	NN.GradientStep(CreateData(), CreateTrainData());
}

int main(){
	Test();
	return 0;
}
