/*
 * DataBase.cpp
 *
 *  Created on: Sep 20, 2020
 *      Author: zhukowych
 */
<<<<<<< HEAD

#include "DataBase.hpp"
using namespace std;


void MYSQLDataBase::Connect(){
	Connection = mysql_init(0);
	Connection = mysql_real_connect(Connection, IP, USERNAME, PASSWORD, DATABASE, 0, NULL, 0);
}

void MYSQLDataBase::Disconnect(){
	mysql_close(Connection);

}

DBMatrixResponse<int>* MYSQLDataBase::GetTrainingDataForReccomenderSVDModel(){
	int NumOfRows;
	int QueryState = mysql_query(Connection, "SELECT user_id, product_id, count FROM history_product;");
	int count =0;
	Result = mysql_store_result(Connection);
	DBMatrixResponse<int>* response = new DBMatrixResponse<int>(mysql_num_rows(Result), 3);
	bool isRowValid = true;
	if(!QueryState){

		while(Row=mysql_fetch_row(Result)){
			DBRow<int> NewRow(3);
			isRowValid = true;
			for (int i=0; i<3; i++){
				if (Row[i]!=NULL){
					NewRow.push(atoi(Row[i]));
				}else{
					isRowValid = false;
				}
			}

			if(isRowValid){
				response->push(NewRow);
			}
		}

	}
	mysql_free_result(Result);
	return response;
}

void MYSQLDataBase::InsertUsersVectors(Matrix<float>* UserMatrix){
	Matrix<float>::indexer_iterator it;
	string result_query;
	stringstream query;
	query << "INSERT INTO user_vectors (user_id, user_vector) VALUES";
	const char* c_result_query;
	int query_state = 0;
	for(it=UserMatrix->indexer_begin(); it!=UserMatrix->indexer_end(); it++){
		query << "(" <<to_string(it->ID) << ", '"<< VectorToString(*(it->vector_)) << "'),";
	}
	result_query = query.str();
	result_query.pop_back();
	c_result_query = result_query.c_str();
	query_state = mysql_query(Connection, c_result_query);
}

inline string MYSQLDataBase::VectorToString(Vector<float>& v){
	string result;
	for(int i=0; i<v.size(); i++){
		result += to_string(v[i]).substr(0, 6) + " ";
	}
	return result;
}


Vector<float> MYSQLDataBase::GetUserVectorByID(int UserID){
	int query_state = 0;
	stringstream query;
	stringstream string_user_vector;
	string temp;
	Vector<float> result(10);
	cout << UserID<< endl;
	query << "SELECT * FROM user_vectors WHERE user_id=" << to_string(UserID);
	const char* result_query = query.str().c_str();

	query_state = mysql_query(Connection, result_query);

	Result = mysql_store_result(Connection);
	cout << mysql_num_rows(Result) << endl;

	while(Row=mysql_fetch_row(Result)){

		string_user_vector<<Row[1];
		cout << 345354 << endl;
		while(getline(string_user_vector, temp, ' ')){
			cout << temp << endl;
		}
	}
	return result;
}

/*

void MYSQLDataBase::InsertTestReccomendations(Matrix<unsigned int>* reccomendations){
	Matrix<unsigned int>::iterator it;

	int qstate = 0;
	int count = 0;
	for(it=reccomendations->begin(); it!=reccomendations->end(); it++){

		stringstream query;
		string product_ids;

		for (int i=1; i<11; i++){
			product_ids += to_string((*it)[i]) + " ";
		}
		query << "INSERT INTO recccomendations(user_id, product_ids) VALUES(" << to_string((*it)[0]) << ",'" << product_ids << "')";
		string query_ = query.str();
		const char* q = query_.c_str();
		qstate = mysql_query(Connection, q);
		cout << count << endl;
		count++;
	}


}
*/
=======
#include<mysql/mysql.h>
#include <string>
using namespace std;

int main(){
    string dummy;
	MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "df4u_rohan", "rohan459", "meds", 0, NULL, 0);

	return 0;
}



>>>>>>> a04c00c78382ea367d8637819e71dc160ad25480
