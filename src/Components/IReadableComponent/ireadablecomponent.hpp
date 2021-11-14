#ifndef READABLE_COMPONENT_HPP
#define READABLE_COMPONENT_HPP

// #include <set>
#include <string>
#include "../component.hpp"

namespace HPS {
  class IReadableComponent : virtual public Component {
  protected:
    std::string label;
  public:
    std::string getLabel();
    virtual DataValue read() = 0;
    std::ostream& outstream(std::ostream &out);
    virtual std::string toString() = 0;
  };
}

#endif
