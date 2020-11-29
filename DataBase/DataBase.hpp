/*
 * DataBase.hpp
 *
 *  Created on: Sep 22, 2020
 *      Author: zhukowych
 */

#ifndef DATABASE_DATABASE_HPP_
#define DATABASE_DATABASE_HPP_
#include<mysql/mysql.h>
#include <string>
#include <sstream>
#include <iostream>
#include "../Containers/DBMatrixResponse.hpp"
#include "../Containers/Matrix.hpp"
using namespace std;

class MYSQLDataBase{
public:
	void Connect();
	void Disconnect();
	DBMatrixResponse<int>* GetTrainingDataForReccomenderSVDModel();
	Vector<float> GetUserVectorByID(int UserID);
	void InsertUsersVectors(Matrix<float>* UserMatrix);
private:
    MYSQL* Connection;
    MYSQL_ROW Row;
    MYSQL_RES* Result;
    const char* IP = "192.168.11.132";
    const char* USERNAME = "max";
    const char* PASSWORD = "beatles";
    const char* DATABASE = "hmarka";

    inline string VectorToString(Vector<float>& v);
};


#endif /* DATABASE_DATABASE_HPP_ */
