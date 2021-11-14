#include "display.hpp"

using std::shared_ptr;
using std::string;
using std::vector;
using HPS::Display;
using HPS::Component;

Display::Display() {}

Display::Display(const double &refreshRate, const string &src)
  : refreshRate(refreshRate), waitingTime(0) {
  this->sourceName = src;

  spdlog::info(this->toString());
}

std::string Display::getType() {
  return constants::DISPLAY;
}

void Display::simulate() {
  spdlog::trace("Display simulation has started.");
  if (!source) return; // TODO throw error
  
  spdlog::debug("[Display] Waiting time = " + std::to_string(waitingTime));

  if (waitingTime <= 0) {
    string buffer = "";
    DataValue data = source->read();
    spdlog::debug("Data read: " + data.toString());
    while (data.valid) {
      buffer += std::to_string(data.value) + " ";
      data = source->read();
    }

    if (buffer.size() > 0) {
      std::cout << buffer << std::endl;
      spdlog::debug("[Display] Output = " + buffer);
    }

    waitingTime = refreshRate;
  }

  waitingTime--;
}

shared_ptr<Component> Display::makeFromFileContent(dict &d) {
  // Check if all necessary keys are present in the dictionary
  vector<string> mandatoryKeys({ constants::REFRESH, constants::SOURCE });
  vector<string> missingKeys = getDictMissingKeys(d, mandatoryKeys);
  if (missingKeys.size() > 0) {
    string errorMsg = "Display dictionary is missing the following key(s): ";
    for (auto const &k : missingKeys) {
      errorMsg += k + " ";
    }
    throw std::invalid_argument(errorMsg);
  }

  spdlog::debug("Creating Display...");

  double refreshRate = std::stod(d[constants::REFRESH]);
  string sourceName = d[constants::SOURCE];

  return shared_ptr<Component>(new Display(refreshRate, sourceName));
}

std::string Display::toString() {
  std::stringstream ss;
  ss << constants::TYPE << ": " << this->getType() << " = {" << std::endl;
  ss << "\t" << constants::SOURCE << ": " << sourceName << std::endl;
  ss << "\t" << constants::REFRESH << ": " << refreshRate << std::endl;
  ss << "}" << std::endl;
  return ss.str();
}

std::ostream & HPS::operator<<(std::ostream &os, Display &d) {
  return d.outstream(os);
};
