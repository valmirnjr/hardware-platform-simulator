#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include <vector>
#include <map>
#include <string>
#include <memory>
#include "../component.hpp"
#include "../../FileImporter/fileimporter.hpp"
#include "../../Common/common.hpp"

namespace HPS {
  // class Component; // Forward declaration to avoid circular include problem
  class Platform : public Component {
  private:
    static const std::string type;
    static std::map<std::string, std::shared_ptr<Component>> factoryMap;
    FileImporter importer;
    std::vector<std::shared_ptr<Component>> components;
    std::vector<std::string> compFilenames;
    std::string dir;
    std::string filename;

  public:
    Platform();
    Platform(std::string, std::string);
    Platform(dict&);
    static std::map<std::string, std::shared_ptr<Component>> initMap();
    void simulate();
    std::shared_ptr<Component> makeFromFileContent(dict&);
    void addDependencies(std::shared_ptr<Component>&, dict&);
    void load();
    void bindComponents();
    std::vector<std::string> getFilenamesFromContent(dict);
  };

  std::string getContentType(dict&, const std::string);
}


#endif