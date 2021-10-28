#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <memory>
#include <string>
#include "../Readable/readable.hpp"
#include "../../CircularBuffer/circularbuffer.hpp"

// Used in memory.cpp
#include <exception>
#include <iostream>

namespace HPS {
  typedef CircularBuffer<double> MemContent;

  class Memory : public ReadableComponent {
    std::shared_ptr<ReadableComponent> source;
    std::unique_ptr<MemContent> content;
    std::string label;
    double accessTime;
    int size;
    
  public:
    Memory();
    Memory(std::string, double, int);
    void simulate();
    DataValue read();
    std::shared_ptr<Component> makeFromFileContent(dict&);
    std::string getLabel();
  };

  bool isValueValid(double);
}

#endif