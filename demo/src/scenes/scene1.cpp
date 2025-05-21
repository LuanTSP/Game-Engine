#include "../../../include/scene.hpp"
#include "../../../include/renderSystem.hpp"
#include <filesystem>


class SceneSoldier : public Scene {
  public:
  using Scene::Scene;

  void init() override {
    // Load resources
    std::cout << std::filesystem::current_path().string() << std::endl;
    resourceManager->loadTexture("soldier-idle","/home/luantsp/Documentos/Projetos/GameEngine/demo/assets/textures/Soldier/Soldier/Soldier-Idle.png");
    resourceManager->loadTexture("soldier-walk","/home/luantsp/Documentos/Projetos/GameEngine/demo/assets/textures/Soldier/Soldier/Soldier-Walk.png");
    resourceManager->loadTexture("soldier-hurt","/home/luantsp/Documentos/Projetos/GameEngine/demo/assets/textures/Soldier/Soldier/Soldier-Hurt.png");
    resourceManager->loadTexture("soldier-attack-1","/home/luantsp/Documentos/Projetos/GameEngine/demo/assets/textures/Soldier/Soldier/Soldier-Attack01.png");
    resourceManager->loadTexture("soldier-attack-2","/home/luantsp/Documentos/Projetos/GameEngine/demo/assets/textures/Soldier/Soldier/Soldier-Attack02.png");
    resourceManager->loadTexture("soldier-attack-3","/home/luantsp/Documentos/Projetos/GameEngine/demo/assets/textures/Soldier/Soldier/Soldier-Attack03.png");
    resourceManager->loadTexture("soldier-death","/home/luantsp/Documentos/Projetos/GameEngine/demo/assets/textures/Soldier/Soldier/Soldier-Death.png");
    
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
        if (event.type == sf::Event::KeyPressed) {
          if (event.key.code == sf::Keyboard::R) {
            return true;
          }
        }
    
        return false;
      }, 
      [this](sf::Event& event) {
      this->setSceneToChange("scene-orc");
    });
  }
};