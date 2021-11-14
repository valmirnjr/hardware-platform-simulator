#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <memory>
#include "../IBindableComponent/ibindablecomponent.hpp"

// Used by display.cpp
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

namespace HPS {
  class Display : public IBindableComponent {
    int refreshRate;
    int waitingTime;
  
  public:
    Display();
    Display(const double&, const std::string&);
    std::string getType();
    void simulate();
    std::shared_ptr<Component> makeFromFileContent(dict&);
    std::string toString();
  };

  std::ostream & operator<<(std::ostream&, Display&);
}

#endif