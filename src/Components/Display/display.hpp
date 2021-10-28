#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <memory>
#include "../Readable/readable.hpp"

// Used by display.cpp
#include <string>
#include <vector>
#include <iostream>

namespace HPS {
  class Display : public Component {
    std::shared_ptr<ReadableComponent> source;
    double refreshRate;
  
  public:
    Display();
    Display(const double&);
    void simulate();
    std::shared_ptr<Component> makeFromFileContent(dict&);
  };
}

#endif