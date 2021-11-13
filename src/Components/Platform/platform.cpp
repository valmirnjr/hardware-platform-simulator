#include "platform.hpp"

// TODO remove these imports from here
#include "../Bus/bus.hpp"
#include "../CPU/cpu.hpp"
#include "../Display/display.hpp"
#include "../Memory/memory.hpp"

using std::map;
using std::string;
using std::shared_ptr;
using HPS::Component;
using HPS::IReadableComponent;
using HPS::IBindableComponent;
using HPS::Platform;
using HPS::dict;

const string Platform::type = HPS::constants::PLATFORM;

Platform::Platform() {}

/**
 * @brief Creates a platform from a textfile.
 * @param dir the directory path to the platform text file.
 * @param filename the platform base filename.
 */
Platform::Platform(std::string dir, std::string filename) : dir(dir), filename(filename) {
  dict content = importer.importAsDict(dir + filename);
  string compType = getContentType(content, dir);

  if (compType != constants::PLATFORM) {
    string err_string = "The file " + filename + " does not contain a platform description.";
    spdlog::error(err_string);
    throw std::runtime_error(err_string);
  }

  compFilenames = getFilenamesFromContent(content);
  HPS::print(compFilenames);
}

Platform::Platform(dict &fc) {
  return;
}

std::string Platform::getType() {
  return constants::PLATFORM;
}

/**
 * @brief Simulates each component inside the platform.
 */
void Platform::simulate() {
  spdlog::trace("The platform simulation has started.");
  for (auto &c : components) {
    c->simulate();
  }
}

/**
 * @brief Loads all the components described in the platform file.
 */
void Platform::load() {
  spdlog::trace("Loading components in the platform...");
  for (auto const &filename : compFilenames) {
    dict content = importer.importAsDict(dir + filename);
    
    string compType = getContentType(content, dir);

    if (factoryMap.count(compType) == 0) {
      // If no constructor was defined for this component type...
      throw std::runtime_error("Error: unknown compType \"" + compType + "\"\n");
    }

    std::cout << "Loading " << compType << std::endl;

    // Create new component of base class type
    shared_ptr<Component> newComp = factoryMap[compType]->makeFromFileContent(content);

    if (content.count(constants::SOURCE) > 0) { // Bindable type
      // Cast the new comp to the child type and save it separately
      bindableComps.push_back(
        std::dynamic_pointer_cast<IBindableComponent>(newComp)
      );
    }
    if (content.count(constants::LABEL)) { // Readable type
      readableComps.push_back(
        std::dynamic_pointer_cast<IReadableComponent>(newComp)
      );
    }
    components.push_back(newComp);
    addDependencies(components.back(), content);
  }
}

shared_ptr<Component> Platform::makeFromFileContent(HPS::dict &fc) {
  shared_ptr<Component> comp(new Platform(fc));
  return comp;
}

void Platform::addDependencies(shared_ptr<Component> &comp, dict &content) {
  if (comp->getType() == constants::CPU) {
    vec2d<string> programContent = importer.importAsVector(dir + content[constants::PROGRAM]); // TODO try catch this

    // Downcasting to be able to set the CPU program
    dynamic_cast<CPU&>(*comp).setProgram(Program(programContent));
    // std::cout << dynamic_cast<CPU&>(*comp);
  }
}

void Platform::bindComponents() {
  for (auto const &comp : bindableComps) {
    shared_ptr<IReadableComponent> src = findSourceWithLabel(comp->getSourceName());
    if (src == nullptr) {
      throw std::runtime_error("Source with name \"" + comp->getSourceName() + "\" could not be found.");
    }
    comp->bind(src);
  }
}

map<string, shared_ptr<Component>> Platform::initMap() {
  map<string, shared_ptr<Component>> m;
  m.emplace(constants::PLATFORM, shared_ptr<Component>(new Platform()));
  m.emplace(constants::BUS, shared_ptr<Component>(new Bus()));
  m.emplace(constants::CPU, shared_ptr<Component>(new CPU()));
  m.emplace(constants::DISPLAY, shared_ptr<Component>(new Display()));
  m.emplace(constants::MEMORY, shared_ptr<Component>(new Memory()));

  return m;
}

std::string Platform::getLabel() {
  return label;
}

std::vector<std::string> Platform::getFilenamesFromContent(dict content) {
  std::vector<string> filenames;
  for (auto const &key : content) {
    // The keys that are NOT in the set are the filenames we want
    if (constants::DEFAULT_KEYS.count(key.first) == 0) {
      filenames.push_back(key.first);
    }
  }
  return filenames;
}

std::string HPS::getContentType(dict &content, const string rootPath) {
  if (content.count(constants::TYPE) > 0) {
    return content[constants::TYPE];
  }
  for (auto const &key : content) {
    // If one key is a filename, we consider it as a Platform
    std::ifstream f((rootPath + key.first).c_str());
    if (f.good()) {
      return constants::PLATFORM;
    }
  }
  // The default case it's to suppose we have a Program
  return constants::PROGRAM;
}

shared_ptr<IReadableComponent> Platform::findSourceWithLabel(const string &targetLabel) {
  for (auto const &readableComp : readableComps) {
    if (readableComp->getLabel() == targetLabel) {
      return readableComp;
    }
  }
  return nullptr;
}

std::string Platform::toString() {
  std::stringstream ss;
  ss << constants::PLATFORM << ": " << label << std::endl;
  return ss.str();
}

map<string, shared_ptr<Component>> Platform::factoryMap = initMap();
