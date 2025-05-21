// #include "../include/scene.hpp"
// #include "../include/renderSystem.hpp"
// #include "../include/resourceManager.hpp"
#include "../include/sceneManager.hpp"
#include "src/scenes/scene1.cpp"
#include "src/scenes/scene2.cpp"

int main()
{
  // Make window
  auto window1 = std::make_shared<sf::RenderWindow>(sf::VideoMode(600, 400), "window 1");
  window1->setFramerateLimit(60);

  // Make resource manager and load assets
  auto resourceManager = std::make_shared<ResourceManager>();

  // Make Scene Manager
  SceneManager sceneManager = SceneManager();

  // Make Scenes
  std::shared_ptr sceneSoldier = std::make_shared<SceneSoldier>(window1);
  sceneManager.addScene("scene-soldier", sceneSoldier);

  std::shared_ptr sceneOrc = std::make_shared<SceneOrc>(window1);
  sceneManager.addScene("scene-orc", sceneOrc);

  sceneManager.setActiveScene("scene-orc");
  sceneManager.setActiveScene("scene-soldier");

  // Gameloop
  sf::Event event;
  sf::Clock clock;
  float elapsed;
  while (sceneManager.isRunning())
  {
    elapsed = clock.restart().asSeconds();

    sceneManager.update(elapsed, event);
  }
}