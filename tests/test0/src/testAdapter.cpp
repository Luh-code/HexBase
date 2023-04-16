#include "testAdapter.hpp"

void TestAdapter::helloWorld()
{
  port->module->helloWorld();
}

void TestAdapter::test(int* response)
{
  *response = 0;
}
