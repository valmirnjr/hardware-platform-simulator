#include "cpu.hpp"
#include <iostream>
#include <exception>

using std::unique_ptr;
using std::string;
using HPS::CPU;
using HPS::Component;

CPU::CPU() {}

CPU::CPU(const string &label, const int &numCores, const double &frequency)
  : activeCore(0), numCores(numCores), frequency(frequency) {
  this->label = label;
  std::cout << *this;
}

void CPU::simulate() {}

unique_ptr<Component> CPU::makeFromFileContent(dict &d) {
  string label;
  int numCores;
  double frequency;

  if (d.count(constants::LABEL) > 0) {
    label = d[constants::LABEL];
  }
  if (d.count(constants::CORES) > 0) {
    numCores = cstrToInt(d[constants::CORES].c_str());
    if (numCores <= 0) {
      throw std::invalid_argument("CPU Number of cores should be positive.");
    }
  }
  if (d.count(constants::FREQUENCY) > 0) {
    char *p;
    frequency = std::stod(d[constants::FREQUENCY]);
    if (frequency <= 0.0) {
      throw std::invalid_argument("CPU Frequency should be positive.");
    }
  }
  
  return unique_ptr<Component>(new CPU(label, numCores, frequency));
}

void CPU::setProgram(Program p) {
  prog = p;
}

std::ostream& CPU::outstream(std::ostream &out) {
  out << constants::TYPE << ": {" << std::endl;
  out << "\t" << constants::LABEL << ": " << label << std::endl;
  out << "\t" << constants::CORES << ": " << numCores << std::endl;
  out << "\t" << constants::FREQUENCY << ": " << frequency << std::endl;
  // out << "\t" << constants::PROGRAM << ": " <<  << std::endl;
  out << "}" << std::endl;
  return out;
}

std::ostream & HPS::operator<<(std::ostream &os, CPU &b) {
  return b.outstream(os);
};