#pragma once
#include <memory>
#include "entityManager.hpp"
#include <SFML/Graphics.hpp>

class System {
  public:
  std::shared_ptr<EntityManager> entityManager;
  std::shared_ptr<sf::RenderWindow> window;

  public:
  System(
    std::shared_ptr<sf::RenderWindow> window,
    std::shared_ptr<EntityManager> entityManager) { 
      this->entityManager = entityManager;
      this->window = window;
  }

  virtual ~System() = default;

  virtual void update() = 0;
};