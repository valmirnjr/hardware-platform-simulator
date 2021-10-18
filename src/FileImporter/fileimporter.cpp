#include "fileimporter.hpp"

using HPS::FileImporter;
using HPS::constants::FileStyle;
using std::string;
using std::map;

FileImporter::FileImporter() {}

FileImporter::FileImporter(string fn) : filename(fn) {
}

void FileImporter::loadProps() {
  string line;
  string key;
  string val;
  std::ifstream file(filename);
  
  if (file.is_open()) {
    while (std::getline(file, line)) {
      std::stringstream ss(line);

      while (std::getline(ss, key, ':')) {
        // TODO: Check whether the ':' was found or not
        // TODO: Treat case where key-values are in two different lines
        std::string next;
        while (ss.rdbuf()->in_avail() > 0) {
          if (next.size() > 0) {
            val += " ";
          }
          ss >> next;
          val.append(next);
        }
        
        // Remove spaces
        trim(key);
        trim(val);

        // std::cout << key << ": ";
        // std::cout << val << std::endl;

        // Save property
        content[key] = val;
        
        key.clear();
        val.clear();
      }
    }
  }
}

void FileImporter::loadPropsByLine() {
  std::ifstream file(filename);
}

HPS::dict FileImporter::import(string fn="") {
  content = dict();
  if (!fn.empty()) {
    filename = fn;
  }
  loadProps();
  return content;
}

// trim from start (in place)
void HPS::ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
void HPS::rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
void HPS::trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}
