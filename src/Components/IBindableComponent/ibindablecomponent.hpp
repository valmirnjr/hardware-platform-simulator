#ifndef BINDABLE_COMPONENT_HPP
#define BINDABLE_COMPONENT_HPP

#include <memory>
#include <string>
#include <set>
#include "../component.hpp"
#include "../IReadableComponent/ireadablecomponent.hpp"
#include "../../Common/common.hpp"

namespace HPS {
  class IBindableComponent : virtual public Component {
  protected:
    std::string sourceName;
    std::shared_ptr<IReadableComponent> source;
  public:
    void bind(std::shared_ptr<IReadableComponent> src);
    const std::string& getSourceName();
    virtual ~IBindableComponent() = 0; // To make class abstract
  };
}

#endif
