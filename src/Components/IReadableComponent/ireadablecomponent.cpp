#include "ireadablecomponent.hpp"

using HPS::IReadableComponent;

std::string IReadableComponent::getLabel() {
  return label;
}

IReadableComponent::~IReadableComponent() { }
