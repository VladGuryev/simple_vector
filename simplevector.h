#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <cstdlib>
#include <algorithm>
using namespace std;

template <typename T>
class SimpleVector {
public:
  SimpleVector() = default;
  explicit SimpleVector(size_t size);
  SimpleVector(const SimpleVector& other);
  SimpleVector& operator=(const SimpleVector& rhs);
  ~SimpleVector();
  T& operator[](size_t index);
  T* begin();
  T* end();
  const T* begin() const;
  const T* end() const;
  size_t Size() const;
  size_t Capacity() const;
  void PushBack(const T& value);

private:
  size_t size = 0;
  size_t capacity = 0;
  T* data = nullptr;
  void reallocate(size_t new_size);
};



template<typename T>
SimpleVector<T>::SimpleVector(size_t size):
  size(size), capacity(size), data(new T[size])
{
}

template<typename T>
SimpleVector<T>::SimpleVector(const SimpleVector &other)
{
  if(this != &other){
    size = other.size;
    capacity = other.capacity;
    data = new T[other.capacity];
    copy(other.begin(), other.end(), begin());
  }
}

template<typename T>
SimpleVector<T> &SimpleVector<T>::operator=(const SimpleVector &rhs)
{
  if(rhs.size < this->capacity){
    copy(rhs.begin(), rhs.end(), begin());
    size = rhs.size;
  } else {
    //copy-swap idiome
    SimpleVector<T> tmp(rhs);
    swap(tmp.data, data);
    swap(tmp.size, size);
    swap(tmp.capacity, capacity);
  }
  return *this;
}

template<typename T>
SimpleVector<T>::~SimpleVector(){
  delete[] data;
}

template<typename T>
T& SimpleVector<T>::operator[](size_t index){
  return data[index];
}

template<typename T>
T* SimpleVector<T>::begin(){
  return data;
}

template<typename T>
T* SimpleVector<T>::end(){
  return data + size;
}

template<typename T>
const T *SimpleVector<T>::begin() const{
  return data;
}

template<typename T>
const T* SimpleVector<T>::end() const{
  return data + size;
}

template<typename T>
size_t SimpleVector<T>::Size() const{
  return size;
}

template<typename T>
size_t SimpleVector<T>::Capacity() const{
  return capacity;
}

template<typename T>
void SimpleVector<T>::PushBack(const T &value){
  size++;
  if(capacity == 0){
    capacity = 1;
    data = new T[capacity];
  }
  if(size == capacity){
    capacity *= 2;
    reallocate(capacity);
  }
  data[size - 1] = value;
}

template<typename T>
void SimpleVector<T>::reallocate(size_t new_size) {
  T* temp_buffer = new T[new_size];
  copy(begin(), end(), temp_buffer);
  delete [] data;
  data = temp_buffer;
}

#endif // SIMPLEVECTOR_H
