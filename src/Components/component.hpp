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
    void virtual simulate() = 0;
    virtual std::unique_ptr<Component> makeFromFileContent(HPS::dict) = 0;
  };
}

#endif