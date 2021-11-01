#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include <vector>
#include <map>
#include <string>
#include <memory>
#include "../component.hpp"
#include "../IBindableComponent/ibindablecomponent.hpp"
#include "../IReadableComponent/ireadablecomponent.hpp"
#include "../../FileImporter/fileimporter.hpp"
#include "../../Common/common.hpp"

// Used by platform.cpp
#include <exception>

namespace HPS {
  class Platform : public Component {
  private:
    static const std::string type;
    static std::map<std::string, std::shared_ptr<Component>> factoryMap;
    FileImporter importer;
    std::vector<std::shared_ptr<Component>> components;
    std::vector<std::shared_ptr<IBindableComponent>> bindableComps;
    std::vector<std::shared_ptr<IReadableComponent>> readableComps;
    std::vector<std::string> compFilenames;
    std::string dir;
    std::string filename;
    std::string label;

  public:
    Platform();
    Platform(std::string, std::string);
    Platform(dict&);
    std::string getType();
    static std::map<std::string, std::shared_ptr<Component>> initMap();
    void simulate();
    std::shared_ptr<Component> makeFromFileContent(dict&);
    void addDependencies(std::shared_ptr<Component>&, dict&);
    void load();
    void bindComponents();
    std::string getLabel();
    std::vector<std::string> getFilenamesFromContent(dict);
    std::shared_ptr<IReadableComponent> findSourceWithLabel(const std::string&);
  };

  std::string getContentType(dict&, const std::string);
}

#endif
