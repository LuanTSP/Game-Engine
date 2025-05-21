#include "../../../include/scene.hpp"
#include "../../../include/renderSystem.hpp"

class SceneOrc : public Scene {
  public:
  using Scene::Scene;

  void init() override {
    // Load resources
    resourceManager->loadTexture("orc-idle", "/home/luantsp/Documents/Projetos/GameEngine/demo/assets/textures/Orc/Orc/Orc-Idle.png");
    resourceManager->loadTexture("orc-walk", "/home/luantsp/Documents/Projetos/GameEngine/demo/assets/textures/Orc/Orc/Orc-Walk.png");
    resourceManager->loadTexture("orc-hurt", "/home/luantsp/Documents/Projetos/GameEngine/demo/assets/textures/Orc/Orc/Orc-Hurt.png");
    resourceManager->loadTexture("orc-attack-1", "/home/luantsp/Documents/Projetos/GameEngine/demo/assets/textures/Orc/Orc/Orc-Attack01.png");
    resourceManager->loadTexture("orc-attack-2", "/home/luantsp/Documents/Projetos/GameEngine/demo/assets/textures/Orc/Orc/Orc-Attack02.png");
    resourceManager->loadTexture("orc-death", "/home/luantsp/Documents/Projetos/GameEngine/demo/assets/textures/Orc/Orc/Orc-Death.png");
    
    // Make Orc
    auto orc = this->entityManager->createEntity("orc");
    this->entityManager->addComponent<AnimatedSpriteComponent>(
      orc, 
      resourceManager->getTexture("orc-idle"),
      100, 100, 6, 0.1f, 0
    );
    this->entityManager->addComponent<ScaleAnimatedSpriteComponent>(orc, 5, 5);

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
      [this, orc](sf::Event& event) {
      this->entityManager->addComponent<AnimatedSpriteComponent>(
        orc, 
        resourceManager->getTexture("orc-idle"),
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
      [this, orc](sf::Event& event) {
      this->entityManager->addComponent<AnimatedSpriteComponent>(
        orc, 
        resourceManager->getTexture("orc-death"),
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
      [this, orc](sf::Event& event) {
      this->entityManager->addComponent<AnimatedSpriteComponent>(
        orc, 
        resourceManager->getTexture("orc-hurt"),
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
      [this, orc](sf::Event& event) {
      this->entityManager->addComponent<AnimatedSpriteComponent>(
        orc, 
        resourceManager->getTexture("orc-walk"),
        100, 100, 6, 0.1, 0
      );
      this->entityManager->addComponent<ScaleAnimatedSpriteComponent>(orc, -5, 5);
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
      [this, orc](sf::Event& event) {
      this->entityManager->addComponent<AnimatedSpriteComponent>(
        orc, 
        resourceManager->getTexture("orc-walk"),
        100, 100, 6, 0.1, 0
      );
      this->entityManager->addComponent<ScaleAnimatedSpriteComponent>(orc, 5, 5);
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
      [this, orc](sf::Event& event) {
      this->entityManager->addComponent<AnimatedSpriteComponent>(
        orc, 
        resourceManager->getTexture("orc-attack-1"),
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
      [this, orc](sf::Event& event) {
      this->entityManager->addComponent<AnimatedSpriteComponent>(
        orc, 
        resourceManager->getTexture("orc-attack-2"),
        100, 100, 6, 0.1, 0
      );
    });

    this->attachTrigger(
      [](sf::Event& event) {
        if (event.type == sf::Event::KeyPressed) {
          if (event.key.code == sf::Keyboard::R) {
            return true;
          }
        }
    
        return false;
      }, 
      [this](sf::Event& event) {
      this->setSceneToChange("scene-soldier");
    });
  }
};