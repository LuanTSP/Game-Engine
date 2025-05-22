#include "engine.hpp"

namespace engine {
  Engine::Engine() {
    this->sceneManager = std::make_shared<SceneManager>();
    this->isRunning = false;
  }

  void Engine::init() {
    this->sceneManager->init();
  }

  void Engine::run() {
    Log::log("Engine running...");
    this->isRunning = true;

    // Gameloop
    sf::Event event; // sfml events
    sf::Clock clock; // sfml clock
    float elapsed;   // elapsd time in seconds since last frame
    while (this->isRunning)
    {
      // update elapsed time
      elapsed = clock.restart().asSeconds();

      // update scene manager
      this->sceneManager->update(elapsed, event);
    }
  }

  void Engine::shutdown() {
    Log::log("Engine shutdown with success");
    this->isRunning = false;
  }
}