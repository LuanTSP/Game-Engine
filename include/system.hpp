#pragma once
#include "entityManager.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

class System {
public:
  std::shared_ptr<EntityManager> entityManager;
  std::shared_ptr<sf::RenderWindow> window;

public:
  System(std::shared_ptr<sf::RenderWindow>& window, std::shared_ptr<EntityManager>& entityManager) :
    window(window),
    entityManager(entityManager)
  {}

  virtual ~System() = default;

  virtual void update(float elapsed) = 0;
};
