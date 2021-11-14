#ifndef CIRCULAR_BUFFER_HPP
#define CIRCULAR_BUFFER_HPP

#include <exception>

namespace HPS {
  template<typename T>
  class CircularBuffer {
    int capacity;
    int size;
    T *values;
    T *head;
    T *tail;
  
  public:
    CircularBuffer();
    ~CircularBuffer();
    CircularBuffer(int);
    T read();
    void write(T&);
    int getSize();
    int getCapacity();
  };

  template<typename T>
  CircularBuffer<T>::CircularBuffer() { }

  template<typename T>
  CircularBuffer<T>::~CircularBuffer() {
      delete []values;
  }

  template<typename T>
  CircularBuffer<T>::CircularBuffer(int cap) : capacity(cap), size(0) {
    values = new T[cap];
    head = tail = values;
  }

  template<typename T>
  T CircularBuffer<T>::read() {
    if (size <= 0) {
      throw std::out_of_range("Trying to read from empty buffer.");
    }
    double val = *head;
    head++;
    if (head == &values[capacity - 1]) {
      head = values;
    }
    size--;
    return val;
  }

  template<typename T>
  void CircularBuffer<T>::write(T &data) {
    if (size < capacity) {
      if (size == 0) {
        tail = head;
      } else if (tail == &values[capacity - 1]) { 
        tail = values;
      } else {
        tail += 1;
      }
      *tail = data;
      size++;
    } else if (size == capacity) {
      tail = head;
      head += 1;
      if (head == &values[capacity - 1]) {
        head = values;
      }
      *tail = data;
    } else {
      throw std::out_of_range("CircularBuffer size error.");
    }
  }

  template<typename T>
  int CircularBuffer<T>::getSize() {
    return size;
  }

  template<typename T>
  int CircularBuffer<T>::getCapacity() {
    return capacity;
  }
}

#endif
