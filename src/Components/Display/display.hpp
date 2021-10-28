#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <memory>
#include "../component.hpp"

namespace HPS {
  class Display : public Component {
    std::shared_ptr<Component> source;
    double refreshRate;
  
  public:
    Display();
    Display(dict&);
    void simulate();
    std::shared_ptr<Component> makeFromFileContent(dict&);
  };
}

#endif