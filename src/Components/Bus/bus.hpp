#ifndef BUS_HPP
#define BUS_HPP

#include <memory>
#include "../component.hpp"

namespace HPS {
  class Bus : public Component {
  public:
    Bus();
    Bus(dict&);
    void simulate();
    std::unique_ptr<Component> makeFromFileContent(dict);
  };
}

#endif