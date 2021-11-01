#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <string>
#include <memory>
#include "../Common/common.hpp"

namespace HPS {
  class Component {
  public:
    virtual std::string getType() = 0;
    virtual void simulate() = 0;
    virtual std::shared_ptr<Component> makeFromFileContent(dict&) = 0;
  };
}

#endif