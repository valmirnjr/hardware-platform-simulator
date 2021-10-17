#ifndef CPU_HPP
#define CPU_HPP

#include "../component.hpp"

namespace HPS {
  class CPU : public Component {
  public:
    CPU();
    CPU(dict&);
    void simulate();
    std::unique_ptr<Component> makeFromFileContent(dict);
  };
}


#endif