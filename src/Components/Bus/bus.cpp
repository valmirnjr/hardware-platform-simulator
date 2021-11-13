#include "bus.hpp"

using std::string;
using std::vector;
using std::shared_ptr;
using HPS::Bus;
using HPS::Component;
using HPS::DataValue;

const string Bus::type = constants::BUS;

Bus::Bus() {}

Bus::Bus(string label, string src, int width) : readCount(0), width(width) {
  this->label = label;
  this->sourceName = src;

  spdlog::info(this->toString());
}

std::string Bus::getType() {
  return constants::BUS;
}

void Bus::simulate() {
  spdlog::trace(this->getLabel() + " simulation has started.");

  // Move pending values to ready
  while (!pending.empty()) {
    ready.push(pending.front());
    pending.pop();
    spdlog::debug("[" + this->getLabel() + "] Moving pending value to ready...");
  }
  spdlog::info("[" + this->getLabel() + "] " + std::to_string(ready.size()) + " ready value(s).");

  // Read W values and store them if they valid
  DataValue newData;
  int i;
  for (i = 0; i < width; i++) {
    newData = source->read();
    if (newData.valid) {
      pending.push(newData);
    } else {
      break;
    }
  }
  spdlog::info("[" + this->getLabel() + "] " + std::to_string(i) + " value(s) added to pending.");
}

DataValue Bus::read() {
  readCount++;
  DataValue oldest = {
    false, // validity
    0      // value
  };

  if (ready.size() > 0) {
    oldest = ready.front();
    ready.pop();
  }

  spdlog::info("[" + this->getLabel() + "] " + "Oldest value: " + oldest.toString());
  return oldest;
}

shared_ptr<Component> Bus::makeFromFileContent(dict &d) {
  // Check if all necessary keys are present in the dictionary
  vector<string> mandatoryKeys({ constants::LABEL, constants::SOURCE, constants::WIDTH });
  vector<string> missingKeys = getDictMissingKeys(d, mandatoryKeys);
  if (missingKeys.size() > 0) {
    string errorMsg = "Bus dictionary is missing the following key(s): ";
    for (auto const &k : missingKeys) {
      errorMsg += k + " ";
    }
    throw std::runtime_error(errorMsg);
  }

  spdlog::debug("Creating Bus: " + d[constants::LABEL]);

  string label = d[constants::LABEL];
  string sourceName = d[constants::SOURCE];
  int width = atoi(d[constants::WIDTH].c_str());

  return shared_ptr<Component>(new Bus(label, sourceName, width));
}

std::string Bus::toString() {
  std::stringstream ss;
  ss << constants::TYPE << ": " << this->getType() << " = {" << std::endl;
  ss << "\t" << constants::LABEL << ": " << label << std::endl;
  ss << "\t" << constants::WIDTH << ": " << width << std::endl;
  ss << "\t" << constants::SOURCE << ": " << sourceName << std::endl;
  ss << "}" << std::endl;
  return ss.str();
}

std::ostream & HPS::operator<<(std::ostream &os, Bus &b) {
  return b.outstream(os);
};
