#ifndef __HEX_TEST_ADAPTER_HPP__
#define __HEX_TEST_ADAPTER_HPP__

#include "hexagon.hpp"
#include "helloWorldPort.hpp"
#include <stdio.h>

class HelloWorldAdapter : public Hexagon::Adapter<HelloWorldPort>
{
public:
  virtual void helloWorld() = 0;
};

class TestAdapter : public HelloWorldAdapter
{
public:
  virtual void test(int* response) override;
  virtual void helloWorld() override;
};


#endif /* end of include guard: __HEX_TEST_ADAPTER_HPP__ */
