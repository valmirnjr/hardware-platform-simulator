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
  content.push(val);
}
