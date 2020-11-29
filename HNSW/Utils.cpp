/*
 * Utils.cpp
 *
 *  Created on: Oct 17, 2020
 *      Author: zhukowych
 */


#include "Utils.hpp"


float Distance(float* first_vector, float* second_vector){
	float distance = 0;
	for (int i=0; i<DataLength; i++){
		distance+= pow((first_vector[i] - second_vector[i]), 2.0);
	}
	return distance;
}

