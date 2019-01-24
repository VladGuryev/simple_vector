#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <cstdlib>
#include <algorithm>
using namespace std;

template <typename T>
class SimpleVector {
public:
  SimpleVector() = default;
  explicit SimpleVector(size_t size, const T& value = T()):
  vec_size(size), volume(2 * size), buffer(new T[volume])
  {
    for(size_t i = 0; i < vec_size; ++i){
      buffer[i] = value;
    }
  }
  ~SimpleVector(){
    delete[] buffer;
  }

  T& operator[](size_t index){
    return buffer[index];
  }

  T* begin(){
    return buffer;
  }
  T* end(){
    return buffer + vec_size;
  }

  const T* begin() const{
    return buffer;
  }
  const T* end() const{
    return buffer + vec_size;
  }

  size_t Size() const{
    return vec_size;
  }
  size_t Capacity() const{
    return volume;
  }

  void PushBack(const T& value){
    vec_size++;
    if(volume == 0){
      volume = 1;
      buffer = new T[volume];
    }
    if(vec_size == volume){
        volume *= 2;
        reallocate(volume);
    }
    buffer[vec_size - 1] = value;
  }

private:
  size_t vec_size = 0;
  size_t volume = 0;
  T* buffer = nullptr;

  void reallocate(size_t new_size) {
      T* temp_buffer = new T[new_size];
      copy(begin(), end(), temp_buffer);
      delete [] buffer;
      buffer = temp_buffer;
  }
};

#endif // SIMPLEVECTOR_H
