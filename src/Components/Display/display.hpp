#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <memory>
#include "../component.hpp"

namespace HPS {
  class Display : public Component {
  public:
    Display();
    Display(dict&);
    void simulate();
    std::unique_ptr<Component> makeFromFileContent(dict&);
  };
}

#endif