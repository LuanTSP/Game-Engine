#pragma once
#include <SFML/Graphics.hpp>
#include "entityManager.hpp"
#include "system.hpp"
#include "resourceManager.hpp"
#include <functional>
#include <vector>


struct EventTrigger {
  std::function<bool(sf::Event&)> condition;
  std::function<void(sf::Event&)> action;
};

class Scene {
  private:  
  bool running = true;
  std::vector<std::shared_ptr<System>> systems;
  
  public:
  std::vector<EventTrigger> triggers;
  std::shared_ptr<sf::RenderWindow> window;
  std::shared_ptr<EntityManager> entityManager;
  std::shared_ptr<ResourceManager> resourceManager;

  public:
  Scene(
    std::shared_ptr<sf::RenderWindow>& window, 
    std::shared_ptr<ResourceManager>& resourceManager,
    std::shared_ptr<EntityManager>& entityManager) {
    this->window = window;
    this->resourceManager = resourceManager;
    this->entityManager = entityManager;
  }

  ~Scene() = default;

  virtual void update(float elapsed, sf::Event& event) {
    this->window->clear();

    // Update events
    while (this->window->pollEvent(event)) {
      for (const auto &trigger : this->triggers) {
        if (trigger.condition(event)) {
          trigger.action(event);
        }
      }
    }

    // Update entity manager
    this->entityManager->update();

    // Update all systems
    for (auto& system : this->systems) {
      system->update(elapsed);
    }

    this->window->display();
  }

  bool isRunning() { return this->running; }

  void end() { 
    this->window->close();
    this->running = false; 
  }

  // System Functionality
  template <typename T>
  void addSystem() {
    this->systems.push_back(std::make_shared<T>(this->window, this->entityManager));
  }

  // Trigger
  void attachTrigger(
    std::function<bool(sf::Event&)> condition,
    std::function<void(sf::Event&)> action) 
  {    
    this->triggers.push_back({condition, action});
  }
};
