#include "cpu.hpp"

using std::shared_ptr;
using std::string;
using std::vector;
using HPS::CPU;
using HPS::Component;
using HPS::DataValue;

CPU::CPU() {}

CPU::CPU(const string &label, const int &numCores, const double &frequency)
  : activeCore(0), numCores(numCores), frequency(frequency) {
  this->label = label;

  spdlog::info(this->toString());
}

std::string CPU::getType() {
  return constants::CPU;
}

void CPU::simulate() {
  spdlog::trace(this->getLabel() + " simulation has started.");
  
  Instruction inst;
  for (int i = 0; i < frequency; i++) {
    inst = prog.compute();
    spdlog::debug("[" + this->getLabel() + "] Executing " + inst.toString());

    double result = inst.execute();
    reg.write(result);
    spdlog::debug("[" + this->getLabel() + "] Result = " + std::to_string(result));
  }
}

DataValue CPU::read() {
  DataValue oldest = {
    false, // validity
    0      // value
  };

  if (!reg.isEmpty()) {
    oldest.value = reg.read();
    oldest.valid = true;
  }

  return oldest;
}

/**
 * @brief Creates a CPU from a dict if the dict arguments are good.
 * @returns A shared_ptr to a CPU object
 */
shared_ptr<Component> CPU::makeFromFileContent(dict &d) {
  // Check if all necessary keys are present in the dictionary
  vector<string> mandatoryKeys({ constants::LABEL, constants::CORES, constants::FREQUENCY });
  vector<string> missingKeys = getDictMissingKeys(d, mandatoryKeys);
  if (missingKeys.size() > 0) {
    string errorMsg = "CPU dictionary is missing the following key(s): ";
    for (auto const &k : missingKeys) {
      errorMsg += k + " ";
    }
    throw std::runtime_error(errorMsg);
  }

  spdlog::debug("Creating CPU: " + d[constants::LABEL]);

  string label = d[constants::LABEL];

  int numCores = cstrToInt(d[constants::CORES].c_str());
  if (numCores <= 0) {
    throw std::invalid_argument("CPU Number of cores should be positive.");
  }

  double frequency = std::stod(d[constants::FREQUENCY]);
  if (frequency <= 0.0) {
    throw std::invalid_argument("CPU Frequency should be positive.");
  }
  
  return shared_ptr<Component>(new CPU(label, numCores, frequency));
}

void CPU::setProgram(const Program &p) {
  prog = p;
  // std::cout << "Setting program: " << prog;
}

std::string CPU::toString() {
  std::stringstream ss;
  ss << constants::TYPE << ": " << this->getType() << " = {" << std::endl;
  ss << "\t" << constants::LABEL << ": " << label << std::endl;
  ss << "\t" << constants::CORES << ": " << numCores << std::endl;
  ss << "\t" << constants::FREQUENCY << ": " << frequency << std::endl;
  ss << "}" << std::endl;
  return ss.str();
}

std::ostream & HPS::operator<<(std::ostream &os, CPU &b) {
  return b.outstream(os);
};
