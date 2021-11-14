#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <memory>
#include <string>
#include "../IReadableComponent/ireadablecomponent.hpp"
#include "../IBindableComponent/ibindablecomponent.hpp"
#include "../../CircularBuffer/circularbuffer.hpp"

// Used in memory.cpp
#include <exception>
#include <iostream>
#include <sstream>

namespace HPS {
  typedef CircularBuffer<double> MemContent;

  class Memory : public IReadableComponent, IBindableComponent {
    std::unique_ptr<MemContent> content;
    int accessTime;
    int waitingTime;
    int size;
    
  public:
    Memory();
    Memory(std::string, std::string, double, int);
    std::string getType();
    void simulate();
    DataValue read();
    std::shared_ptr<Component> makeFromFileContent(dict&);
    std::string toString();
    using IReadableComponent::outstream;
  };

  bool isValueValid(double);
  std::ostream & operator<<(std::ostream&, Memory&);
}

#endif