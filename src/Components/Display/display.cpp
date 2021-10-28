#include "display.hpp"

using std::shared_ptr;
using std::string;
using std::vector;
using HPS::Display;
using HPS::Component;

Display::Display() {}

Display::Display(const double &refreshRate) : refreshRate(refreshRate) { }

void Display::simulate() {
  if (!source) return;
  
  static int waitingTime = 0;
  string buffer = "";
  if (waitingTime <= 0) {
    DataValue data = source->read();
    while (data.valid) {
      buffer += std::to_string(data.value);
      data = source->read();
    }
    waitingTime = refreshRate;
  }
  waitingTime--;
  std::cout << buffer;
}

shared_ptr<Component> Display::makeFromFileContent(dict &d) {
  // Check if all necessary keys are present in the dictionary
  vector<string> mandatoryKeys({ constants::REFRESH });
  vector<string> missingKeys = getDictMissingKeys(d, mandatoryKeys);
  if (missingKeys.size() > 0) {
    string errorMsg = "Display dictionary is missing the following key(s): ";
    for (auto const &k : missingKeys) {
      errorMsg += k + " ";
    }
    throw std::invalid_argument(errorMsg);
  }

  std::cout << "Creating Display" << std::endl;

  double refreshRate = std::stod(d[constants::REFRESH]);

  return shared_ptr<Component>(new Display(refreshRate));
}
