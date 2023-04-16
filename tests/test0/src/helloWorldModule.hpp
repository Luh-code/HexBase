#ifndef __HEX_HELLO_WORLD_MODULE_CPP
#define __HEX_HELLO_WORLD_MODULE_CPP

#include "hexBase/module.hpp"
#include <stdio.h>

class HelloWorldModule : public Hexagon::Module
{
public:
  inline void helloWorld()
  {
    printf("%s\n", "Hello World from a Module!");
  }
};

#endif /* end of include guard: __HEX_HELLO_WORLD_MODULE_CPP */
