/*
 * DBMatrixResponse.h
 *
 *  Created on: Oct 30, 2020
 *      Author: zhukowych
 */

#ifndef CONTAINERS_DBMATRIXRESPONSE_HPP_
#define CONTAINERS_DBMATRIXRESPONSE_HPP_
#include<stdint.h>
#include<mysql/mysql.h>
#include <iostream>
#include <memory>
using namespace std;

/* TODO : Test */

template<class T>
class DBRow{
public:
	DBRow(){};
	DBRow(int Length_){
		Length = Length_;
		elements = shared_ptr<T[]>(new T[Length],[](auto p){ delete[] p;});
	};
	~DBRow(){};
	T operator[](int index){
		if(index>(Length-1))std::runtime_error("Index Error");
		return elements[index];
	};
	void push(T value);
private:
	shared_ptr<T[]> elements;
	int Length;
	int CurrentLength = 0;
};


template<class T>
void DBRow<T>::push(T value){
	if(Length==CurrentLength)return;
	elements[CurrentLength] = value;
	CurrentLength++;
}

template<class T>
class DBMatrixResponse {
public:
	class iterator{
	public:
		iterator(){};
		iterator(DBRow<T>* pointer_){pointer = pointer_;};
		iterator operator++(){return iterator(pointer++);};
		iterator operator++(int){return iterator(pointer++);};
		bool operator!=(const iterator& it){if(it.pointer==pointer){return false;}else{return true;}};
		void operator=(const iterator& it){pointer = it.pointer;};
		DBRow<T> operator*(){return *pointer;};
	private:
		DBRow<T>* pointer;
	};

	DBMatrixResponse(int NumOfRows_, int LengthOfRow_){
		LengthOfRow = LengthOfRow_;
		NumOfRows = NumOfRows_;
		Rows = shared_ptr<DBRow<T>[]>(new DBRow<T>[NumOfRows]);
	};
	~DBMatrixResponse(){
		cout << "RESPO" << endl;
	};

	iterator begin();
	iterator end();
	void push(DBRow<T> Row);
private:
	int NumOfRows;
	int CurrentSize=0;
	int LengthOfRow;
	shared_ptr<DBRow<T>[]> Rows;
};

template<class T>
void DBMatrixResponse<T>::push(DBRow<T> Row){
	if(CurrentSize==NumOfRows)return;
	Rows[CurrentSize] = Row;
	CurrentSize++;
}

template<class T>
typename DBMatrixResponse<T>::iterator DBMatrixResponse<T>::begin(){
	return DBMatrixResponse<T>::iterator(Rows.get());
}

template<class T>
typename DBMatrixResponse<T>::iterator DBMatrixResponse<T>::end(){
	return DBMatrixResponse<T>::iterator(Rows.get()+CurrentSize);
}


#endif /* CONTAINERS_DBMATRIXRESPONSE_HPP_ */
