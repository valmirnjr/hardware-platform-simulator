#ifndef BUS_HPP
#define BUS_HPP

#include <string>
#include <vector>
#include <queue>
#include <memory>
#include <fstream>
#include "../../Common/common.hpp"
#include "../Readable/readable.hpp"

namespace HPS {
  class Bus : public ReadableComponent {
    std::string label;
    static const std::string type;
    int width;
    std::string sourceName;
    std::vector<DataValue> pending;
    std::queue<DataValue> ready;
    int readCount;
    
  public:
    Bus();
    Bus(dict&);
    void simulate();
    std::shared_ptr<Component> makeFromFileContent(dict&);
    std::string getLabel();
    bool bind(std::shared_ptr<Component>);
    DataValue read();
    int getReadCount();
    std::ostream& outstream(std::ostream&);
  };

  std::ostream & operator<<(std::ostream&, Bus&);
}

#endif