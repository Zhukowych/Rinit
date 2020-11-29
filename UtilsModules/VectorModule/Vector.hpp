
#ifndef VECTOR_HPP_
#define VECTOR_HPP_

template<class T>
class vector{
public:
  vector(int MaxLength_);
  ~vector();
  int Push(T NewItem);
  int length();
  T& operator[](int Index);
private:
  T* ItemsVector;
  int MaxLength;
  int InsertedLength;
};

#endif
