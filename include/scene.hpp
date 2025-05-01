#pragma once
#include <SFML/Graphics.hpp>
#include "entityManager.hpp"
#include "system.hpp"
#include "resourceManager.hpp"
#include <vector>


class Scene {
  private:  
  bool running = true;
  std::vector<std::shared_ptr<System>> systems;

  public:
  sf::RenderWindow& window;
  std::shared_ptr<EntityManager> entityManager;
  std::shared_ptr<ResourceManager> resourceManager;

  public:
  Scene(sf::RenderWindow& window) : 
    window(window), 
    entityManager(std::make_shared<EntityManager>()),
    resourceManager(std::make_shared<ResourceManager>())
  {}

  ~Scene() = default;

  // Core Functionality
  virtual void handleEvents(sf::Event event) = 0;

  virtual void update() {
    this->window.clear();

    this->entityManager->update();

    for (auto& system : this->systems) {
      system->update();
    }

    this->window.display();
  }

  bool isRunning() { return this->running; }

  void end() { 
    this->window.close();
    this->running = false; 
  }

  // System Functionality
  template <typename T>
  void addSystem() {
    this->systems.push_back(std::make_shared<T>(this->window, this->entityManager));
  }

  // Resource Manager Functionality
  void loadTexture(std::string& name, std::string& path) {
    this->resourceManager->loadTexture(name, path);
  }

  void loadTexture(const char * name, const char * path) {
    std::string sname = name;
    std::string spath = path;
    this->resourceManager->loadTexture(sname, spath);
  }

  void unloadTexture(std::string name) {
    this->resourceManager->unloadTexture(name);
  }

  std::shared_ptr<sf::Texture> getTexture(std::string name) {
    return this->resourceManager->getTexture(name);
  }

  // Entity Manager Functionality
  template <typename T, typename... Args>
  void addComponent(std::size_t id, Args &&...args) {
    this->entityManager->addComponent<T>(id, std::forward<Args>(args)...);
  }
  
};
