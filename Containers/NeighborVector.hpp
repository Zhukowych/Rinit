
#include <stdint.h>
template<class T>
class NeighborVector{
public:
	class iterator{
	public:
		iterator(){};
		iterator(T* pointer_){pointer = pointer_;};
		iterator operator++(){return iterator(pointer++);};
		iterator operator++(int){return iterator(pointer++);};
		bool operator!=(const iterator& it){if(it.pointer==pointer){return false;}else{return true;}};
		void operator=(const iterator& it){pointer = it.pointer;};
		T operator*(){return *pointer;};
		T* GetPointer(){return pointer;};
	private:
		T* pointer;
	};
	NeighborVector(){MaxSize=11;};
	NeighborVector(int MaxSize_);
	iterator begin();
	iterator end();
	void push(T NewElement);
	void pop();
	int size();
private:
	T* value;
	int MaxSize;
	int CurrentSize = 0;
};


template<class T>
NeighborVector<T>::NeighborVector(int MaxSize_){
	MaxSize = MaxSize_;
	value = new T[MaxSize];
}

template<class T>
int NeighborVector<T>::size(){
	return CurrentSize;
}

template<class T>
void NeighborVector<T>::push(T NewElement){
	if(CurrentSize!=MaxSize) value[CurrentSize] = NewElement;
	CurrentSize++;
}

template<class T>
void NeighborVector<T>::pop(){
	if(CurrentSize!=0)value[CurrentSize-1] = nullptr;
	CurrentSize--;
}

template<class T>
typename NeighborVector<T>::iterator NeighborVector<T>::begin(){
	return iterator(value);
}

template<class T>
typename NeighborVector<T>::iterator NeighborVector<T>::end(){
	return iterator(value+CurrentSize);
}
