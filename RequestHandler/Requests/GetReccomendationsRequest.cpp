/*
 * GetReccomendationsRequest.cpp
 *
 *  Created on: Sep 19, 2020
 *      Author: zhukowych
 */

#include "Requests.hpp"

void GetReccomendationsRequest::Execute(){
	 ofstream testFile;
	 const char* messange = std::to_string(CommandIntIddentiffer).c_str();
	 testFile.open("test.txt");
	 testFile << messange;
	 testFile.close();
}


