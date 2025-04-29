#include "engine.hpp"

Engine::Engine() {
  this->log = new Log();
}

void Engine::init() {
  log->log("Engine initiated with success");
}

void Engine::run() {
  log->log("Running ...");
}

void Engine::shutdown() {
  log->log("Shutting Down ...");
}