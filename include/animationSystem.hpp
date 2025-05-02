#include "system.hpp"
#include "components.hpp"

class AnimationSystem : public System {
  public:
  using System::System;

  void update() override {
    auto& animations = entityManager->getAllComponents<SpriteComponent>();
    
    for (auto &[id, animComp] : animations) {
      
    }
    // elapsed += clock.restart().asSeconds();
    // if (elapsed >= frameDuration) {
    //   currentFrame = (currentFrame + 1) % numFrames;
    //   sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));
    //   elapsed = 0;
    // }
  }
};