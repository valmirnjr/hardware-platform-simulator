#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <memory>
#include "../IBindableComponent/ibindablecomponent.hpp"

// Used by display.cpp
#include <string>
#include <vector>
#include <iostream>

namespace HPS {
  class Display : public IBindableComponent {
    double refreshRate;
  
  public:
    Display();
    Display(const double&);
    std::string getType();
    void simulate();
    std::shared_ptr<Component> makeFromFileContent(dict&);
  };
}

#endif