#ifndef CIRCULAR_BUFFER_HPP
#define CIRCULAR_BUFFER_HPP

#include <exception>

namespace HPS {
  template<typename T>
  class CircularBuffer {
    int capacity;
    int currentSize;
    T *values;
    T *head;
    T *tail;
  
  public:
    CircularBuffer();
    ~CircularBuffer();
    CircularBuffer(int);
    T read();
    void write(T&);
    int getCurrentSize();
    int getCapacity();
  };

  template<typename T>
  CircularBuffer<T>::CircularBuffer() { }

  template<typename T>
  CircularBuffer<T>::~CircularBuffer() {
      delete []values;
  }

  template<typename T>
  CircularBuffer<T>::CircularBuffer(int cap) : capacity(cap), currentSize(0) {
    values = new T[cap];
    head = tail = values;
  }

  template<typename T>
  T CircularBuffer<T>::read() {
    if (currentSize <= 0) {
      throw std::out_of_range("Trying to read from empty buffer.");
    }
    double val = *head;
    head++;
    if (head == &values[capacity - 1]) {
      head = values;
    }
    currentSize--;
    return val;
  }

  template<typename T>
  void CircularBuffer<T>::write(T &data) {
    if (currentSize < capacity) {
      if (currentSize == 0) {
        tail = head;
      } else if (tail == &values[capacity - 1]) { 
        tail = values;
      } else {
        tail += 1;
      }
      *tail = data;
      currentSize++;
    } else if (currentSize == capacity) {
      tail += 1;
      head += 1;
      *tail = data;
    } else {
      throw std::out_of_range("CircularBuffer size error.");
    }
  }

  template<typename T>
  int CircularBuffer<T>::getCurrentSize() {
    return currentSize;
  }

  template<typename T>
  int CircularBuffer<T>::getCapacity() {
    return capacity;
  }
}

#endif
