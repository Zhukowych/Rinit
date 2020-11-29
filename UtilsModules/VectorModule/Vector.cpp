#include "Vector.hpp"
template class vector<int>;
template class vector<float>;


template<class T>
vector<T>::vector(int MaxLength_){
  ItemsVector = new T[MaxLength_];
  MaxLength = MaxLength_;
}

template<class T>
vector<T>::~vector(){
  delete[] ItemsVector;
}

template<class T>
int vector<T>::Push(T NewItem){
  if((InsertedLength+1) <= MaxLength){
	ItemsVector[InsertedLength] = NewItem;
	InsertedLength++;
	return 0;
  }else{
	return -1;
  }
}

template<class T>
int vector<T>::length(){
  return InsertedLength;
}

template<class T>
T& vector<T>::operator[](int Index){
  return ItemsVector[Index];
}


