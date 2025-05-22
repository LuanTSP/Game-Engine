#pragma once
#include <SFML/Graphics.hpp>
#include "entityManager.hpp"
#include "system.hpp"
#include "resourceManager.hpp"
#include <functional>
#include <vector>

struct EventTrigger
{
  std::function<bool(sf::Event &)> condition;
  std::function<void(sf::Event &)> action;
};

namespace engine {
  class Scene
  {
  private:
    bool running = false;
    std::vector<std::shared_ptr<System>> systems;
    std::string sceneToChange= "";

  public:
    std::vector<EventTrigger> triggers;
    std::shared_ptr<sf::RenderWindow> window = nullptr;
    std::shared_ptr<EntityManager> entityManager = nullptr;
    std::shared_ptr<ResourceManager> resourceManager = nullptr;

  public:
    Scene(std::shared_ptr<sf::RenderWindow> &window);

    ~Scene() = default;

    virtual void update(float elapsed, sf::Event &event)
    {
      this->window->clear();

      // Update events
      while (this->window->pollEvent(event))
      {
        for (const auto &trigger : this->triggers)
        {
          if (trigger.condition(event))
          {
            trigger.action(event);
          }
        }
      }

      // Update entity manager
      this->entityManager->update();

      // Update all systems
      for (auto &system : this->systems)
      {
        system->update(elapsed);
      }

      this->window->display();
    }

    virtual void init() = 0;

    bool isRunning();

    void setRunning(bool running);

    // System Functionality
    template <typename T>
    void addSystem()
    {
      this->systems.push_back(std::make_shared<T>(this->window, this->entityManager));
    }

    // Trigger
    void attachTrigger(std::function<bool(sf::Event &)> condition, std::function<void(sf::Event &)> action);

    std::string getSceneToChange();

    void setSceneToChange(std::string name);

    void setSceneToChange(const char * name);
  };
}