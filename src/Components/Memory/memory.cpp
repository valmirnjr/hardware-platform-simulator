#include "memory.hpp"

using std::unique_ptr;
using std::shared_ptr;
using std::string;
using std::vector;
using HPS::Memory;
using HPS::IReadableComponent;
using HPS::Component;
using HPS::DataValue;
using HPS::CircularBuffer;

Memory::Memory() {}

Memory::Memory(const string label, const string src, const double accessTime, const int size)
  : accessTime(accessTime), size(size), waitingTime(0) {
  this->label = label;
  this->sourceName = src;
  content = unique_ptr<MemContent>(new MemContent(size));

  std::cout << *this;
}

std::string Memory::getType() {
  return constants::MEMORY;
}

void Memory::simulate() {
  spdlog::trace(this->getLabel() + " simulation has started.");
  spdlog::debug("waitingTime = " + std::to_string(waitingTime));

  if (waitingTime <= 0) {
    DataValue data = source->read();
    while (data.valid) {
      content->write(data.value);
      spdlog::info("[" + this->getLabel() + "] Writing " + std::to_string(data.value) + ".");
      data = source->read();
    }
    waitingTime = accessTime;
  }
  waitingTime--;
}

DataValue Memory::read() {
  DataValue data = {
    false, // validity
    0      // value
  };
  if (content->getSize() > 0) {
    data.valid = true;
    data.value = content->read();
  }
  return data;
}

shared_ptr<Component> Memory::makeFromFileContent(dict &d) {
  // Check if all necessary keys are present in the dictionary
  vector<string> mandatoryKeys({ constants::LABEL, constants::SOURCE, constants::ACCESS, constants::SIZE });
  vector<string> missingKeys = getDictMissingKeys(d, mandatoryKeys);
  if (missingKeys.size() > 0) {
    string errorMsg = "Memory dictionary is missing the following key(s): ";
    for (auto const &k : missingKeys) {
      errorMsg += k + " ";
    }
    throw std::invalid_argument(errorMsg);
  }

  std::cout << "Creating Memory: " << d[constants::LABEL] << std::endl;

  string label = d[constants::LABEL];
  string sourceName = d[constants::SOURCE];
  double accessTime = std::stod(d[constants::ACCESS]);
  int size = cstrToInt(d[constants::SIZE].c_str());

  return shared_ptr<Component>(new Memory(label, sourceName, accessTime, size));
}

std::string Memory::toString() {
  std::stringstream ss;
  ss << constants::TYPE << ": " << this->getType() << " = {" << std::endl;
  ss << "\t" << constants::LABEL << ": " << label << std::endl;
  ss << "\t" << constants::SOURCE << ": " << sourceName << std::endl;
  ss << "\t" << constants::ACCESS << ": " << accessTime << std::endl;
  ss << "\t" << constants::SIZE << ": " << size << std::endl;
  ss << "}" << std::endl;
  return ss.str();
}

std::ostream & HPS::operator<<(std::ostream &os, Memory &m) {
  return m.outstream(os);
};
