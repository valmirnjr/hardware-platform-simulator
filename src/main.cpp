#include <iostream>
#include <map>
#include <string>
#include "FileImporter/fileimporter.hpp"

using HPS::FileImporter;

int main() {
  FileImporter fi;
  std::map<std::string, std::string> props = fi.import("/home/valmir/Documentos/Phelma/S9/OOP/Project/hardware-platform-simulator/test/data/testdata_1/program.txt");

  return 0;
}