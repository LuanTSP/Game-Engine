#pragma once
#include <iostream>
#include "log.hpp"

class Engine {
private:
  Log* log;
  
public:
  // Init
  Engine();
  
  // Functions
  void init();

  void run();

  void shutdown();
};