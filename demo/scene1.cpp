#include "scene.hpp"
#include "renderSystem.hpp"

class SceneSoldier : public Scene {
  public:
  using Scene::Scene;

  void init() override {
    // Make Player
    auto player = this->entityManager->createEntity("player");
    this->entityManager->addComponent<AnimatedSpriteComponent>(
      player, 
      resourceManager->getTexture("soldier-idle"),
      100, 100, 6, 0.1f, 0
    );
    this->entityManager->addComponent<ScaleAnimatedSpriteComponent>(player, 5, 5);
    

    // Add Systems
    this->addSystem<RenderSystem>();


    // Add triggers
    this->attachTrigger(
      [](sf::Event& event) {
        if (event.type == sf::Event::KeyPressed) {
          if (event.key.code == sf::Keyboard::Space) {
            return true;
          }
        }
    
        return false;
      }, 
      [this, player](sf::Event& event) {
      this->entityManager->addComponent<AnimatedSpriteComponent>(
        player, 
        resourceManager->getTexture("soldier-idle"),
        100, 100, 4, 0.1, 0
      );
    });

    this->attachTrigger(
      [](sf::Event& event) {
        if (event.type == sf::Event::KeyPressed) {
          if (event.key.code == sf::Keyboard::W) {
            return true;
          }
        }
    
        return false;
      }, 
      [this, player](sf::Event& event) {
      this->entityManager->addComponent<AnimatedSpriteComponent>(
        player, 
        resourceManager->getTexture("soldier-death"),
        100, 100, 4, 0.1, 0
      );
    });

    this->attachTrigger(
      [](sf::Event& event) {
        if (event.type == sf::Event::KeyPressed) {
          if (event.key.code == sf::Keyboard::S) {
            return true;
          }
        }
    
        return false;
      }, 
      [this, player](sf::Event& event) {
      this->entityManager->addComponent<AnimatedSpriteComponent>(
        player, 
        resourceManager->getTexture("soldier-hurt"),
        100, 100, 4, 0.1, 0
      );
    });

    this->attachTrigger(
      [](sf::Event& event) {
        if (event.type == sf::Event::KeyPressed) {
          if (event.key.code == sf::Keyboard::A) {
            return true;
          }
        }
    
        return false;
      }, 
      [this, player](sf::Event& event) {
      this->entityManager->addComponent<AnimatedSpriteComponent>(
        player, 
        resourceManager->getTexture("soldier-walk"),
        100, 100, 6, 0.1, 0
      );
      this->entityManager->addComponent<ScaleAnimatedSpriteComponent>(player, -5, 5);
    });

    this->attachTrigger(
      [](sf::Event& event) {
        if (event.type == sf::Event::KeyPressed) {
          if (event.key.code == sf::Keyboard::D) {
            return true;
          }
        }
    
        return false;
      }, 
      [this, player](sf::Event& event) {
      this->entityManager->addComponent<AnimatedSpriteComponent>(
        player, 
        resourceManager->getTexture("soldier-walk"),
        100, 100, 6, 0.1, 0
      );
      this->entityManager->addComponent<ScaleAnimatedSpriteComponent>(player, 5, 5);
    });

    this->attachTrigger(
      [](sf::Event& event) {
        if (event.type == sf::Event::MouseButtonPressed) {
          if (event.mouseButton.button == sf::Mouse::Button::Left) {
            return true;
          }
        }
    
        return false;
      }, 
      [this, player](sf::Event& event) {
      this->entityManager->addComponent<AnimatedSpriteComponent>(
        player, 
        resourceManager->getTexture("soldier-attack-1"),
        100, 100, 6, 0.1, 0
      );
    });

    this->attachTrigger(
      [](sf::Event& event) {
        if (event.type == sf::Event::MouseButtonPressed) {
          if (event.mouseButton.button == sf::Mouse::Button::Right) {
            return true;
          }
        }
    
        return false;
      }, 
      [this, player](sf::Event& event) {
      this->entityManager->addComponent<AnimatedSpriteComponent>(
        player, 
        resourceManager->getTexture("soldier-attack-2"),
        100, 100, 6, 0.1, 0
      );
    });

    this->attachTrigger(
      [](sf::Event& event) {
        if (event.type == sf::Event::MouseButtonPressed) {
          if (event.mouseButton.button == sf::Mouse::Button::Middle) {
            return true;
          }
        }
    
        return false;
      }, 
      [this, player](sf::Event& event) {
      this->entityManager->addComponent<AnimatedSpriteComponent>(
        player, 
        resourceManager->getTexture("soldier-attack-3"),
        100, 100, 9, 0.1, 0
      );
    });

    this->attachTrigger(
      [](sf::Event& event) {
        if (event.type == sf::Event::Closed) {
          return true;
        }
    
        return false;
      }, 
      [this, player](sf::Event& event) {
      this->window->close();
    });
  }
};