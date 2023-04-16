#include <stdio.h>
#include "testApp.hpp"

int main()
{
  TestApplication app;
  TestAdapter testAdapter {};
  app.changeHelloWorldAdapter(&testAdapter);

  testAdapter.helloWorld();
  return 0;
}
