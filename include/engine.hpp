#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "sceneManager.hpp"
#include "log.hpp"

namespace engine {
  class Engine {
    private:
    bool isRunning = false;

    public:
    std::shared_ptr<SceneManager> sceneManager;

    public:
    // Init
    Engine();

    // Functions
    void init();

    void run();

    void shutdown();
  };
}
