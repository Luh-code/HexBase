#ifndef __HEX_TEST_APP_HPP__
#define __HEX_TEST_APP_HPP__

#include "hexagon.hpp"
#include "testAdapter.hpp"
#include "helloWorldPort.hpp"

class TestApplication : public Hexagon::Application
{
public:
  HelloWorldModule helloWorldModule;

  HelloWorldPort helloWorldPort {helloWorldModule};

public:
  inline void changeHelloWorldAdapter(HelloWorldAdapter* adapter)
  {
    evaluateAdapter(adapter, &helloWorldPort);
  }

  inline void helloWorld()
  {
    printf("%s\n", "Hello World from an adapter!");
  }
};

#endif /* end of include guard: __HEX_TEST_APP_HPP__ */
