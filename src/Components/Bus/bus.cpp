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

  std::cout << *this;
}

std::string Bus::getType() {
  return constants::BUS;
}

void Bus::simulate() {}

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

  std::cout << "Creating Bus: " << d[constants::LABEL] << std::endl;

  string label = d[constants::LABEL];
  string sourceName = d[constants::SOURCE];
  int width = atoi(d[constants::WIDTH].c_str());

  return shared_ptr<Component>(new Bus(label, sourceName, width));
}

std::ostream& Bus::outstream(std::ostream &out) {
  out << constants::TYPE << ": {" << std::endl;
  out << "\t" << constants::LABEL << ": " << label << std::endl;
  out << "\t" << constants::WIDTH << ": " << width << std::endl;
  out << "\t" << constants::SOURCE << ": " << sourceName << std::endl;
  out << "}" << std::endl;
  return out;
}

std::ostream & HPS::operator<<(std::ostream &os, Bus &b) {
  return b.outstream(os);
};
