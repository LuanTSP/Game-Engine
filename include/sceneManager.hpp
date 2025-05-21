#pragma once
#include "scene.hpp"
#include <memory>
#include <unordered_map>
#include "log.hpp"


class SceneManager {
  private:
  std::unordered_map<std::string, std::shared_ptr<Scene>> scenes;
  std::string active = ""; // name of the active scene
  bool running = true;
  
  public:
  SceneManager();

  void addScene(const char * name, std::shared_ptr<Scene> scene);

  void addScene(std::string& name, std::shared_ptr<Scene> scene);

  void removeScene(std::string& name);

  std::shared_ptr<Scene> getScene(std::string name);

  void update(float elapsed, sf::Event &event);

  bool isRunning();

  void setActiveScene(const char * name);
  
  void setActiveScene(std::string name);
};