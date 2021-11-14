#include "ireadablecomponent.hpp"

using HPS::IReadableComponent;

std::string IReadableComponent::getLabel() {
  return label;
}

std::ostream& IReadableComponent::outstream(std::ostream &out) {
  out << this->toString() << std::endl;
  return out;
}
