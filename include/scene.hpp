#pragma once
#include <SFML/Graphics.hpp>
#include "entityManager.hpp"
#include "system.hpp"
#include <vector>


class Scene {
  private:  
  bool running = true;
  std::vector<std::shared_ptr<System>> systems;

  public:
  std::shared_ptr<sf::RenderWindow> window;
  std::shared_ptr<EntityManager> entityManager;

  public:
  Scene(std::shared_ptr<sf::RenderWindow> window) {
    this->window = window;
    this->entityManager = std::make_shared<EntityManager>();
  }

  ~Scene() = default;

  virtual void load() = 0;

  virtual void handleEvents(sf::Event event) = 0;

  virtual void update() {
    // Clear window
    this->window->clear();

    // Update entity manager
    this->entityManager->update();

    // Update all systems
    for (auto& system : this->systems) {
      system->update();
    }

    // Display
    this->window->display();
  }

  template <typename T>
  void addSystem() {
    this->systems.push_back(std::make_shared<T>(this->window, this->entityManager));
  }
  
  bool isRunning() { return this->running; }

  void end() { 
    this->window->close();
    this->running = false; 
  }
};
