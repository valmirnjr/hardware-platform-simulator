#include "component.hpp"
#include <string>

using HPS::Component;

std::string Component::getType() {
  return type;
}

std::string Component::getLabel() {
  return label;
}
