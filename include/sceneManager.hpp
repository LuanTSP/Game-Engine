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

  void addScene(const char * name, std::shared_ptr<Scene> scene) {
    std::string strName = name;
    scene->init();
    this->scenes[strName] = scene;
  }

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
    // Checks if active scene should be changed
    for (auto &[sceneName, scene] : this->scenes) {
      std::string toChange = scene->getSceneToChange();
      if (toChange == "") {
        continue;
      }

      if (scenes.find(toChange) == scenes.end()) {
        throw std::runtime_error("Scene not found");
        Log::err("Scene ", toChange, " not found");
      }

      this->setActiveScene(toChange);
      scene->setSceneToChange("");
    }

    // Updates the active scene if found
    if (this->scenes.find(this->active) != this->scenes.end()) {
      this->scenes[this->active]->update(elapsed, event);
    }
  }

  bool isRunning() {
    return this->running;
  }

  void setActiveScene(const char * name) {
    std::string strName = name;
    this->setActiveScene(strName);
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