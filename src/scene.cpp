#include "../include/scene.hpp"

namespace engine {
  Scene::Scene(std::shared_ptr<sf::RenderWindow> &window)
  {
    this->window = window;
    this->resourceManager = std::make_shared<ResourceManager>();
    this->entityManager = std::make_shared<EntityManager>();
  }

  bool Scene::isRunning() { return this->running; }

  void Scene::setRunning(bool running)
  {
    this->running = running;
  }

  // Trigger
  void Scene::attachTrigger
  (
    std::function<bool(sf::Event &)> condition,
    std::function<void(sf::Event &)> action
  )
  {
    this->triggers.push_back({condition, action});
  }

  std::string Scene::getSceneToChange() {
    return this->sceneToChange;
  }

  void Scene::setSceneToChange(std::string name) {
    this->sceneToChange = name;
  }

  void Scene::setSceneToChange(const char * name) {
    std::string strName = name;
    this->sceneToChange = strName;
  }
}

