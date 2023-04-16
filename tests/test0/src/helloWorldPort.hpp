#ifndef __HEX_HELLO_WORLD_PORT_HPP
#define __HEX_HELLO_WORLD_PORT_HPP

#include "hexagon.hpp"
#include "helloWorldModule.hpp"

class HelloWorldPort : public Hexagon::Port<HelloWorldModule>
{
public:
  inline HelloWorldPort(HelloWorldModule& module)
  {
    this->module = &module;
  }
};

#endif /* end of include guard: __HEX_HELLO_WORLD_PORT_HPP */
