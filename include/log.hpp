#pragma once
#include <iostream>

class Log {
public:
  // Init
  Log();

  // Logging
  template <typename... Args> static void log(Args &&...args) {
    (std::cout << ... << args) << std::endl;
  }

  template <typename... Args> static void err(Args &&...args) {
    std::cerr << "[ERROR]: ";
    (std::cerr << ... << args) << std::endl;
  }

  template <typename... Args> static void info(Args &&...args) {
    std::cout << "[INFO]: ";
    (std::cout << ... << args) << std::endl;
  }
};
