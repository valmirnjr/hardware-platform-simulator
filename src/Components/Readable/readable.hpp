#ifndef READABLE_HPP
#define READABLE_HPP

#include "../component.hpp"
#include "../../Common/common.hpp"

namespace HPS {
  class ReadableComponent : public Component {
  public:
    virtual DataValue read() = 0;
  };
}

#endif
