#include "platform.hpp"
#include "../Bus/bus.hpp"
#include "../CPU/cpu.hpp"
#include "../Display/display.hpp"
#include "../Memory/memory.hpp"

using std::map;
using std::string;
using std::unique_ptr;
using HPS::Component;
using HPS::Platform;
using HPS::dict;

const string Platform::type = HPS::constants::PLATFORM;

Platform::Platform() {}

Platform::Platform(std::string dir, std::string filename) : dir(dir), filename(filename) {
  dict content = importer.import(dir + filename);
  string compType = getContentType(content, dir);

  if (compType != constants::PLATFORM) {
    std::cout << "Error: the file '" << filename << "' doesn't contain a platform description." << std::endl;
    return;
  }

  compFilenames = getFilenamesFromContent(content);
  HPS::print(compFilenames);
}

Platform::Platform(dict &fc) {
  return;
}

void Platform::simulate() {
  for (auto &c : components) {
    c->simulate();
  }
}

void Platform::load() {
  for (auto const &filename : compFilenames) {
    dict content = importer.import(dir + filename);
    // print(content);
    string compType = getContentType(content, dir);

    if (factoryMap.count(compType) > 0) {
      std::cout << "Loading " << compType << std::endl;
      components.push_back(
        factoryMap[compType]->makeFromFileContent(content)
      );
    } else {
      std::cout << "Error: unknown compType: " << compType << std::endl;
    }
  }
}

unique_ptr<Component> Platform::makeFromFileContent(HPS::dict fc) {
  unique_ptr<Component> comp(new Platform(fc));
  return comp;
}

void Platform::bindComponents() {
}

map<string, unique_ptr<Component>> Platform::initMap() {
  map<string, unique_ptr<Component>> m;
  m.emplace(constants::PLATFORM, unique_ptr<Component>(new Platform()));
  m.emplace(constants::BUS, unique_ptr<Component>(new Bus()));
  m.emplace(constants::CPU, unique_ptr<Component>(new CPU()));
  m.emplace(constants::DISPLAY, unique_ptr<Component>(new Display()));
  m.emplace(constants::MEMORY, unique_ptr<Component>(new Memory()));

  return m;
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

map<string, unique_ptr<Component>> Platform::factoryMap = initMap();
