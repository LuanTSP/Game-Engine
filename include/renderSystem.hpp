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
      } else {
        auto center = getCenterPos(window);
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
      } else {
        auto center = getCenterPos(window);
        animSpriteComp->sprite.setPosition(center.x, center.y);
      }

      // Draw with right rotation if angle component exists
      auto ang = this->entityManager->getComponent<AngleComponent>(id);
      if (ang) {
        animSpriteComp->sprite.setRotation(ang->angle);
      }

      // Scale animated sprite
      auto scale = this->entityManager->getComponent<ScaleAnimatedSpriteComponent>(id);
      if (scale) {
        animSpriteComp->sprite.setScale(scale->x, scale->y);
      }

      // Check if should update sprite
      animSpriteComp->elapsed += elapsed;
      if (animSpriteComp->elapsed >= animSpriteComp->frameDuration) {
        animSpriteComp->currentFrame = (animSpriteComp->currentFrame + 1) % animSpriteComp->numFrames;
        animSpriteComp->sprite.setTextureRect(sf::IntRect(animSpriteComp->currentFrame * animSpriteComp->frameWidth, 0, animSpriteComp->frameWidth, animSpriteComp->frameHeight));
        animSpriteComp->elapsed = 0;
      }

      // Draw to the window
      this->window.draw(animSpriteComp->sprite);
    }
  }
};
