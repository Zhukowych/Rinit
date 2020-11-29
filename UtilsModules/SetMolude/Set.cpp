#include "Set.hpp"

template class set<int>;

template<class T>
set<T>::set(int MaxLength_){
  MaxLength = MaxLength_;
  ItemsSet = new T[MaxLength_];
}

template<class T>
set<T>::~set(){
  delete[] ItemsSet;
};


template<class T>
int set<T>::Push(T NewItem){
  int NextCountOfInsertedItems = InsertedItems+1;
  if (NextCountOfInsertedItems>MaxLength || IsInSet(NewItem) ){
	return -1;
  }else{	
	ItemsSet[InsertedItems] = NewItem;
	InsertedItems = NextCountOfInsertedItems;
	return 0;
  }
}

template<class T>
int set<T>::Delete(T Value){
  int ValueIndex = GetValueIndex(Value);
  if (ValueIndex<0) return -1;
  MoveLastItemsAfterDeleting(ValueIndex);
  InsertedItems--;
  return 0;
}

template<class T>
void set<T>::MoveLastItemsAfterDeleting(int IndexOfDeletedItem){
  if ((InsertedItems-1)>IndexOfDeletedItem){
	for (int i=IndexOfDeletedItem; i<InsertedItems; ++i){
	  ItemsSet[i] = ItemsSet[i+1]; 
	}
  }
}

template<class T>
int set<T>::length(){
  return InsertedItems;
}


template<class T>
int set<T>::IsInSet(T Value){
  for (int i=0; i<InsertedItems; ++i){
	if(ItemsSet[i]==Value)return -1;
  }
  return 0;
}

template<class T>
int set<T>::GetValueIndex(T Value){
  for (int i=0; i<InsertedItems;++i){
	if(ItemsSet[i]==Value) return i;
  }
  return -1;
}

template<class T>
T& set<T>::operator[](int Index){
  return *(ItemsSet+Index);
}

