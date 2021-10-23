#ifndef FILE_IMPORTER_HPP
#define FILE_IMPORTER_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include "../Common/common.hpp"

namespace HPS {
  class FileImporter {
  private:
    std::string filename;
  
  public:
    FileImporter();
    FileImporter(std::string);
    void loadProps();
    vec2d<std::string> importAsVector(std::string);
    dict importAsDict(std::string);
  };

  void ltrim(std::string&);
  void rtrim(std::string&);
  void trim(std::string&);
}


#endif
