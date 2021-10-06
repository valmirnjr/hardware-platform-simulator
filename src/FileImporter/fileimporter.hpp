#ifndef FILE_IMPORTER_HPP
#define FILE_IMPORTER_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

namespace HPS {
  class FileImporter {
  private:
    std::string filename;
    std::map<std::string, std::string> props;
  
  public:
    FileImporter();
    FileImporter(std::string);
    std::map<std::string, std::string> getProps();
    void loadProps();
    void loadPropsByLine();
    std::map<std::string, std::string> import(std::string);
  };
}

void ltrim(std::string&);
void rtrim(std::string&);
void trim(std::string&);

#endif
