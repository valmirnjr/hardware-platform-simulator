#include "ibindablecomponent.hpp"

using HPS::IBindableComponent;

void IBindableComponent::bind(std::shared_ptr<IReadableComponent> src) {
  source = src;
}

const std::string& IBindableComponent::getSourceName() {
  return sourceName;
}

std::ostream& IBindableComponent::outstream(std::ostream &out) {
  out << this->toString() << std::endl;
  return out;
}
