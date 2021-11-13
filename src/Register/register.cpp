#include "register.hpp"

using HPS::Register;

Register::Register() {
}

bool Register::isEmpty() {
  return content.empty();
}

double Register::read() {
  double val = content.front();
  content.pop();
  return val;
}

void Register::write(double val) {
  spdlog::debug("[Register] Writing " + std::to_string(val));
  content.push(val);
  spdlog::debug("[Register] Content size = " + std::to_string(content.size()));
}
