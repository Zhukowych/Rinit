

#ifndef IDATA_BASE_HPP_
#define IDATA_BASE_HPP_
<<<<<<< HEAD

#include <mysql/mysql.h>
#include <vector>
using namespace std;

class IDataBase{
public:
	virtual vector<vector<int>>* GetTrainingDataForReccomenderSVDModel()=0;
	virtual vector<vector<int>>* GetTrainingDataForUserLatentNN()=0;
	virtual vector<vector<char*>>* GetTrainingFDataForItemLatentNN()=0;
	virtual vector<int> GetUserDataByID(int ID)=0;
	virtual vector<int> GetItemDataByID(int ID)=0;
	virtual ~IDataBase(){};
private:
	MYSQL* ConnectionToDB;
	MYSQL_RES* QueryResource;
	MYSQL_ROW Row;
=======
#include <mysql/mysql.h>

class IDataBase{

>>>>>>> a04c00c78382ea367d8637819e71dc160ad25480

};

#endif
