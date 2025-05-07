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
  SceneManager() {}

  void addScene(std::string& name, std::shared_ptr<Scene> scene) {
    scene->init();
    this->scenes[name] = scene;
  }

  void removeScene(std::string& name) {
    scenes.erase(name);
    if (name == this->active) {
      this->active = "";
    }
  }

  std::shared_ptr<Scene> getScene(std::string name) {
    if (this->scenes.find(name) != this->scenes.end()) {
      return this->scenes[name];
    }

    return nullptr;
  }

  void update(float elapsed, sf::Event &event) {
    if (this->scenes.find(this->active) != this->scenes.end()) {
      this->scenes[this->active]->update(elapsed, event);
    }
  }

  bool isRunning() {
    return this->running;
  }

  void setActiveScene(std::string name) {    
    // trying to set scene active when there was no active scene previously
    if (this->scenes.find(this->active) == this->scenes.end()) {
      if (this->scenes.find(name) != this->scenes.end()) {
        this->active = name;
        this->scenes[name]->setRunning(true);
        return;
      } else {
        Log::log("Scene with name ", name, " does not exist!");
        throw std::runtime_error("Scene does not exist!");
      }
    } else {
      if (this->scenes.find(name) != this->scenes.end()) {
        this->scenes[this->active]->setRunning(false);
        this->scenes[name]->setRunning(true);
        this->active = name;
      } else {
        Log::log("Scene with name ", name, " does not exist!");
        throw std::runtime_error("Scene does not exist!");
      }
    }
  }
};