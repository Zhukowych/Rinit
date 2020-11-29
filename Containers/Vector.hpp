/*
 * Vector.hpp
 *
 *  Created on: Nov 1, 2020
 *      Author: zhukowych
 */

#ifndef CONTAINERS_VECTOR_HPP_
#define CONTAINERS_VECTOR_HPP_
#include <map>
#include <stdint.h>
#include <random>
#include <string.h>
#include <memory>
#include<iostream>



template<class T>
class Vector{
/* DOC: Vector, which supports math functions. In initializations fills up to random values from 0 to 1 */
public:
	Vector();
	Vector(int MaxSize_);
	Vector(int MaxSize_, std::shared_ptr<T[]> elements_);

	~Vector();


	float dot(const Vector<T>& SecondVector);
	T& operator[](int index);
	void operator+=(const Vector<T>& additor);
	void operator=(const Vector<T>& v);
	Vector<T> operator-(const Vector<T>& subtractor);
	Vector<T> operator*(float multuplier);
	T* GetElements();
	unsigned int size();
	void clear();

private:
	bool isDeleteElementsInDestructor = true;
	std::shared_ptr<T[]> elements;
	int MaxSize = 0;
	bool isUsed = false;

	void CopyElements(std::shared_ptr<T[]> ElementsToCopy);
	void FillUpElements();
	void MultipleElementsTo(float multiplier);
	void SubtractFromElements(std::shared_ptr<T[]> subtractor);
	void AddToElements(std::shared_ptr<T[]> addition);



};
template<class T>
Vector<T>::Vector(){

}
static int c = 0;
template<class T>
Vector<T>::Vector(int MaxSize_){
	MaxSize = MaxSize_;
	elements = std::shared_ptr<T[]>(new T[MaxSize], std::default_delete<T[]>());

	FillUpElements();
}

template<class T>
Vector<T>::Vector(int MaxSize_, std::shared_ptr<T[]> elements_){
	MaxSize = MaxSize_;
	elements = std::shared_ptr<T[]>(new T[MaxSize], std::default_delete<T[]>());
	CopyElements(elements_);
	isDeleteElementsInDestructor = true;
}

template<class T>
Vector<T>::~Vector(){
	if(elements.use_count()>1){

	}

}

template<class T>
void Vector<T>::FillUpElements(){
	std::random_device rd;
	std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for(int i=0; i<MaxSize; i++){
    	elements[i] = dis(gen);
    }
}

template<class T>
float Vector<T>::dot(const Vector<T>& SecondVector){

	float Result = 0;
	for(int i=0; i<MaxSize; i++){
		Result += elements[i]*SecondVector.elements[i];
	}

	return Result;
}

template<class T>
unsigned int Vector<T>::size(){
	return MaxSize;
}

template<class T>
void Vector<T>::clear(){
	delete[] elements;
}

template<class T>
void Vector<T>::CopyElements(std::shared_ptr<T[]> ElementsToCopy){
	for(int i=0; i<MaxSize;i++){
		elements[i] = ElementsToCopy[i];
	}
}

template<class T>
void Vector<T>::operator+=(const Vector<T>& additor){
	AddToElements(additor.elements);
}

template<class T>
void Vector<T>::operator=(const Vector<T>& v){
	elements = v.elements;
	MaxSize = v.MaxSize;
}

template<class T>
Vector<T> Vector<T>::operator-(const Vector<T>& subtractor){
	Vector<T> SubtractedVector(MaxSize, elements);
	SubtractedVector.SubtractFromElements(subtractor.elements);
	return SubtractedVector;
}


template<class T>
Vector<T> Vector<T>::operator*(float multiplier){
	Vector<T> MultipledVector(MaxSize, elements);
	MultipledVector.MultipleElementsTo(multiplier);
	return MultipledVector;
}

template<class T>
T* Vector<T>::GetElements(){
	return elements.get();
}

template<class T>
void Vector<T>::MultipleElementsTo(float multiplier){
	for (int i=0; i<MaxSize; i++){
		elements[i]*=multiplier;
	}
}

template<class T>
void Vector<T>::SubtractFromElements(std::shared_ptr<T[]> subtractor){
	for (int i=0; i<MaxSize; i++){
		elements[i] -= subtractor[i];
	}
}

template<class T>
void Vector<T>::AddToElements(std::shared_ptr<T[]> addition){
	for (int i=0; i<MaxSize; i++){
		elements[i] += addition[i];
	}
}


template<class T>
T& Vector<T>::operator[](int index){
	if(index>MaxSize)elements[0];
	return elements[index];
}

#endif /* CONTAINERS_VECTOR_HPP_ */
