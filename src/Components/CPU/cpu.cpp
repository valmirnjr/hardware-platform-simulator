#include "cpu.hpp"
#include <iostream>

using std::unique_ptr;
using HPS::CPU;
using HPS::Component;

CPU::CPU() {}

CPU::CPU(dict &d) {
  std::cout << "Creating CPU: " << d[constants::LABEL] << std::endl;
}

void CPU::simulate() {}

unique_ptr<Component> CPU::makeFromFileContent(dict d) {
  return unique_ptr<Component>(new CPU(d));
}
