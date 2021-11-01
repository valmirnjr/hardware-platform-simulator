#ifndef BUS_HPP
#define BUS_HPP

#include <string>
#include <vector>
#include <queue>
#include <memory>
#include "../../Common/common.hpp"
#include "../IReadableComponent/ireadablecomponent.hpp"
#include "../IBindableComponent/ibindablecomponent.hpp"

namespace HPS {
  class Bus : public IReadableComponent, public IBindableComponent {
    static const std::string type;
    int width;
    std::vector<DataValue> pending;
    std::queue<DataValue> ready;
    int readCount;
    
  public:
    Bus();
    Bus(dict&);
    void simulate();
    std::shared_ptr<Component> makeFromFileContent(dict&);
    DataValue read();
    int getReadCount();
    std::ostream& outstream(std::ostream&);
  };

  std::ostream & operator<<(std::ostream&, Bus&);
}

#endif