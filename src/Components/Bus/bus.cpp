#include "bus.hpp"
#include <iostream>

using std::string;
using std::unique_ptr;
using HPS::Bus;
using HPS::Component;

const string Bus::type = constants::BUS;

Bus::Bus() {}

Bus::Bus(dict &d) : readCount(0) {
  if (d.count(constants::LABEL) > 0) {
    label = d[constants::LABEL];
  }
  if (d.count(constants::SOURCE) > 0) {
    sourceName = d[constants::SOURCE];
  }
  if (d.count(constants::WIDTH) > 0) {
    width = atoi(d[constants::WIDTH].c_str());
  }

  std::cout << *this;
}

void Bus::simulate() {}

unique_ptr<Component> Bus::makeFromFileContent(dict d) {
  return unique_ptr<Component>(new Bus(d));
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
