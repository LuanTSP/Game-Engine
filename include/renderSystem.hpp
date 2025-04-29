#pragma once
#include <SFML/Graphics.hpp>
#include "system.hpp"
#include "entityManager.hpp"

class RenderSystem : public System {
  private:
  EntityManager* entityManager;
  sf::RenderWindow* window;

  public:
  void Init() override {
    Log::info("Render system inited with success!");
  }

  void Update() override {
    auto& sprites = entityManager->getAllComponents<SpriteComponent>();

    for (auto& [id, spriteComp] : sprites) {
      this->window->draw(spriteComp->sprite);
    }
  }

  void End() override {
    Log::info("Render system ended with success!");
  }
};
