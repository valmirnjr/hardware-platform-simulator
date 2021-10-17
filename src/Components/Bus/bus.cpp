#include "bus.hpp"
#include <iostream>

using std::unique_ptr;
using HPS::Bus;
using HPS::Component;

Bus::Bus() {}

Bus::Bus(dict &d) {
  std::cout << "Creating Bus: " << d[constants::LABEL] << std::endl;
}

void Bus::simulate() {}

unique_ptr<Component> Bus::makeFromFileContent(dict d) {
  return unique_ptr<Component>(new Bus(d));
}
