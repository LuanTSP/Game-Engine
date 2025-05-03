#pragma once
#include "system.hpp"
#include "utils.hpp"
#include <SFML/Graphics.hpp>

class RenderSystem : public System {
public:
  using System::System;

  void update(float elapsed) override {
    // Get all static sprites
    auto &sprites = entityManager->getAllComponents<StaticSpriteComponent>();

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

      this->window.draw(spriteComp->sprite);
    }

    // Get all animated sprites
    auto &animatedSprites = entityManager->getAllComponents<AnimatedSpriteComponent>();

    for (auto &[id, animSpriteComp] : animatedSprites) {
      // Draw with right position if positions component exists
      auto pos = this->entityManager->getComponent<PositionComponent>(id);
      
      if (pos) {
        animSpriteComp->sprite.setPosition(pos->x, pos->y);
      
      } else { // Draw to center of screen of positions not given
        auto center = getCenterPos(window, animSpriteComp->sprite);
        
        animSpriteComp->sprite.setPosition(center.x, center.y);
      }

      // Draw with right rotation if angle component exists
      auto ang = this->entityManager->getComponent<AngleComponent>(id);
      if (ang) {
        animSpriteComp->sprite.setRotation(ang->angle);
      }

      // Check if should update sprite
      animSpriteComp->elapsed += elapsed;
      if (animSpriteComp->elapsed >= animSpriteComp->frameDuration) {
        animSpriteComp->currentFrame = (animSpriteComp->currentFrame + 1) % animSpriteComp->numFrames;
        animSpriteComp->sprite.setTextureRect(sf::IntRect(animSpriteComp->currentFrame * animSpriteComp->frameWidth, 0, animSpriteComp->frameWidth, animSpriteComp->frameHeight));
        animSpriteComp->elapsed = 0;
      }

      this->window.draw(animSpriteComp->sprite);
    }
  }
};
