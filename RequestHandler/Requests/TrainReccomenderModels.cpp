/*
 * TrainReccomenderModels.cpp
 *
 *  Created on: Sep 19, 2020
 *      Author: zhukowych
 */

#include "Requests.hpp"

void TrainReccomenderModels::Execute(){
	 ofstream testFile;
	 const char* messange = "train";
	 testFile.open("test.txt");
	 testFile << messange;
	 testFile.close();
}


