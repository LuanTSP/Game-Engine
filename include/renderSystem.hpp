#pragma once
#include "system.hpp"
#include "utils.hpp"
#include <SFML/Graphics.hpp>

class RenderSystem : public System {
public:
  using System::System;

  void update() override {
    // Get all sprites
    auto &sprites = entityManager->getAllComponents<SpriteComponent>();

    for (auto &[id, spriteComp] : sprites) {
      // Draw with right position if positions component exists
      auto pos = this->entityManager->getComponent<PositionComponent>(id);
      
      if (pos) {
        spriteComp->sprite.setPosition(pos->x, pos->y);
      
      } else { // Draw to center of screen of positions not given
        auto center = getCenterPos(window, spriteComp->sprite);
        
        spriteComp->sprite.setPosition(center.x, center.y);
      }

      // Draw with right rotation if angle component exists
      auto ang = this->entityManager->getComponent<AngleComponent>(id);
      if (ang) {
        spriteComp->sprite.setRotation(ang->angle);
      }

      this->window->draw(spriteComp->sprite);
    }
  }
};
