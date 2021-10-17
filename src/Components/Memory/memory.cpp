#include "memory.hpp"
#include <iostream>

using std::unique_ptr;
using HPS::Memory;
using HPS::Component;

Memory::Memory() {}

Memory::Memory(dict &d) {
  std::cout << "Creating Memory: " << d[constants::LABEL] << std::endl;
}

void Memory::simulate() {}

unique_ptr<Component> Memory::makeFromFileContent(dict d) {
  return unique_ptr<Component>(new Memory(d));
}


