#include "../include/engine.hpp"
#include "src/scenes/scene1.cpp"
#include "src/scenes/scene2.cpp"

int main()
{
  // Make Engine
  auto engine = engine::Engine();
  engine.init();

  // Make window
  auto window1 = std::make_shared<sf::RenderWindow>(sf::VideoMode(600, 400), "window 1");
  window1->setFramerateLimit(60);

  // Make Scenes
  std::shared_ptr sceneSoldier = std::make_shared<SceneSoldier>(window1);
  engine.sceneManager->addScene("scene-soldier", sceneSoldier);

  std::shared_ptr sceneOrc = std::make_shared<SceneOrc>(window1);
  engine.sceneManager->addScene("scene-orc", sceneOrc);

  engine.sceneManager->setActiveScene("scene-soldier");

  engine.run();

  engine.shutdown();
}