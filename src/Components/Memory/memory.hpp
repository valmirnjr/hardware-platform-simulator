#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <memory>
#include "../component.hpp"

namespace HPS {
  class Memory : public Component {
    public:
    Memory();
    Memory(dict&);
    void simulate();
    std::shared_ptr<Component> makeFromFileContent(dict&);
  };
}

#endif