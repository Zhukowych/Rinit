


#ifndef MATRIX_HPP
#define MATRIX_HPP
#include "Vector.hpp"
#include<iostream>
using namespace std;


template<class T>
class Matrix{
public:
	struct VectorIDPair{
		VectorIDPair(){};
		VectorIDPair(Vector<T>* _vector, int ID_){vector_=_vector;ID=ID_;};
		Vector<T>* vector_;
		int ID;
	};
	class iterator{
	public:
		iterator(){};
		iterator(Vector<T>* pointer_){pointer = pointer_;};
		iterator operator++(){return iterator(pointer++);};
		iterator operator++(int){return iterator(pointer++);};
		bool operator!=(const iterator& it){if(it.pointer==pointer){return false;}else{return true;}};
		void operator=(const iterator& it){pointer = it.pointer;};
		Vector<T>& operator*(){return *pointer;};
	private:
		Vector<T>* pointer;
	};
	class indexer_iterator{
	public:
		typedef std::map<int, int>::iterator map_iterator;
		indexer_iterator(){};
		indexer_iterator(Vector<T>* pointer_, map_iterator it_){pointer = pointer_;it=it_;};
		indexer_iterator operator++(){return indexer_iterator(pointer++, it++);};
		indexer_iterator operator++(int){return indexer_iterator(pointer++, it++);};
		bool operator!=(const indexer_iterator& nit){if(nit.pointer==pointer){return false;}else{return true;}};
		void operator=(const indexer_iterator& nit){pointer = nit.pointer;it = nit.it;};
		VectorIDPair* operator->(){pair_ = VectorIDPair(pointer, it->first); return &pair_;};
	private:
		Vector<T>* pointer;
		map_iterator it;
		VectorIDPair pair_;
	};

	Matrix();
	Matrix(int Length_, int SizeOfVector_);
	Matrix(std::map<int, int> indexer_, int Length_, int SizeOfRow_);
	~Matrix();
	Vector<T>& operator[](int index);
	void operator+=(Matrix<float>* other);
	Vector<float> dot(Vector<float> input);
	unsigned int size();
	unsigned int vector_size();
	void clear();

	iterator begin();
	iterator end();
	indexer_iterator indexer_begin();
	indexer_iterator indexer_end();
private:
	bool isUseIndexer = false;
	std::map<int, int> indexer;
	int Length;
	int SizeOfVector;
	std::shared_ptr<Vector<T>[]> Vectors;

	void InitializateVectors();
	Vector<float> GorizontalDot(Vector<float> input);
	Vector<float> VerticalDot(Vector<float> input);
};

template<class T>
Matrix<T>::Matrix(){

}

template<class T>
Matrix<T>::Matrix(int Length_, int SizeOfVector_){
	Length = Length_;
	SizeOfVector = SizeOfVector_;
	InitializateVectors();
}

template<class T>
Matrix<T>::Matrix(std::map<int, int> indexer_, int Length_, int SizeOfRow_){
	Length = Length_;
	SizeOfVector = SizeOfRow_;
	indexer = indexer_;
	isUseIndexer = true;

	InitializateVectors();
}


template<class T>
Matrix<T>::~Matrix(){
	cout << Vectors.use_count() << endl;
}

template<class T>
Vector<T>& Matrix<T>::operator[](int index){
	if(isUseIndexer){
		return Vectors[indexer[index]];
	}else{
		if(index>Length)throw std::runtime_error("Index error");
		return Vectors[index];
	}
}

template<class T>
void Matrix<T>::operator+=(Matrix<float>* other){
	for(int i=0; i<Length; i++){
		Vectors[i]+=(*other)[i];
	}
}

template<class T>
Vector<float> Matrix<T>::dot(Vector<float> input){
	if(input.size()==SizeOfVector)
		return GorizontalDot(input);
	else
		return VerticalDot(input);
}

template<class T>
Vector<float> Matrix<T>::GorizontalDot(Vector<float> input){
	Vector<float> result(Length);
	for(int i=0;i<Length;i++){
		result[i] = Vectors[i].dot(input);
	}
	return result;
}

template<class T>
Vector<float> Matrix<T>::VerticalDot(Vector<float> input){
	Vector<float> result(SizeOfVector);
	float vertical_dot = 0;
	for(int i=0;i<SizeOfVector;i++){
		for(int j=0; j<Length; j++){
			vertical_dot += Vectors[j][i]*input[j];
		}
		result[i] = vertical_dot;
		vertical_dot = 0;
	}
	return result;
}

template<class T>
unsigned int Matrix<T>::size(){
	return Length;
}

template<class T>
unsigned int Matrix<T>::vector_size(){
	return SizeOfVector;
}

template<class T>
void Matrix<T>::clear(){
	Matrix<T>::iterator it;
	for(it=begin(); it!=end();it++){
		(*it).clear();
	}
	delete[] Vectors;
}

template<class T>
void Matrix<T>::InitializateVectors(){
	Vectors = std::shared_ptr<Vector<T>[]>(new Vector<T>[Length], std::default_delete<Vector<T>[]>());
	for (int i=0; i<Length;i++){
		Vectors[i] = Vector<T>(SizeOfVector);
	}
}

template<class T>
typename Matrix<T>::iterator Matrix<T>::begin(){
	return Matrix<T>::iterator(Vectors.get());
}

template<class T>
typename Matrix<T>::iterator Matrix<T>::end(){
	return Matrix<T>::iterator(Vectors.get()+Length);
}

template<class T>
typename Matrix<T>::indexer_iterator Matrix<T>::indexer_begin(){
	return Matrix<T>::indexer_iterator(Vectors.get(), indexer.begin());
}

template<class T>
typename Matrix<T>::indexer_iterator Matrix<T>::indexer_end(){
	return Matrix<T>::indexer_iterator(Vectors.get()+Length, indexer.end());
}

/* UTIL */

static Matrix<float> different_length_dot(Vector<float>& v1, Vector<float>& v2){
	Matrix<float> result(v1.size(), v2.size());
	for(int i=0; i<v2.size(); i++){
		for(int j=0; j<v1.size(); j++){
			result[j][i] = v1[j]*v2[i];
		}
	}
	return result;
}


#endif
