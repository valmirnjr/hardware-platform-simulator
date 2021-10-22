#include "display.hpp"
#include <iostream>

using std::unique_ptr;
using HPS::Display;
using HPS::Component;

Display::Display() {}

Display::Display(dict &d) {
  std::cout << "Creating Display: " << d[constants::LABEL] << std::endl;
}

void Display::simulate() {}

unique_ptr<Component> Display::makeFromFileContent(dict &d) {
  return unique_ptr<Component>(new Display(d));
}


