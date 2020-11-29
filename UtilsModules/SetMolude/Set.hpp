
#ifndef SET_HPP_
#define SET_HPP_

template<class T>
class set{
public:
  set(int MaxLength_);
  ~set();
  int Push(T NewItem);
  int Delete(T Value);
  int length();
  T& operator[](int Index);
private:
  T* ItemsSet;
  int MaxLength;
  int InsertedItems = 0;
  int IsInSet(T Value);
  int GetValueIndex(T Value);
  void MoveLastItemsAfterDeleting(int IndexOfDeletedItem);
};

#endif
