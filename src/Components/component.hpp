#ifndef COMPONENT_FACTORY_HPP
#define COMPONENT_FACTORY_HPP

#include <string>
#include <memory>
#include "../Common/common.hpp"

namespace HPS {
  class Component {
  protected:
    std::string type;
    std::string label;

  public:
    std::string getType();
    std::string getLabel();
    virtual void simulate() = 0;
    virtual std::unique_ptr<Component> makeFromFileContent(dict&) = 0;
  };
}

#endif