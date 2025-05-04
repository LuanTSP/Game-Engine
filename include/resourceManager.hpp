#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include "log.hpp"

class ResourceManager {
  private:
  std::unordered_map<std::string, std::shared_ptr<sf::Texture>> textures;
  
  public:
  ResourceManager() {};

  void loadTexture(std::string& name, std::string& path) {
    auto texture = std::make_shared<sf::Texture>();
    texture->loadFromFile(path);

    if (!texture) {
      Log::err("Failed to load texture from '", path, "'");
      throw std::runtime_error("Failed to load texture!");
    }

    if (this->textures.find(name) != this->textures.end()) {
      Log::err("Texture with same name already exists");
      throw std::runtime_error("Texture with same name already exists");
    }
    
    this->textures[name] = texture;
  }

  void loadTexture(const char* name, const char* path) {
    auto texture = std::make_shared<sf::Texture>();
    texture->loadFromFile(path);

    if (!texture) {
      Log::err("Failed to load texture from '", path, "'");
      throw std::runtime_error("Failed to load texture!");
    }

    if (this->textures.find(name) != this->textures.end()) {
      Log::err("Texture with same name already exists");
      throw std::runtime_error("Texture with same name already exists");
    }
    
    this->textures[name] = texture;
  }

  void unloadTexture(std::string name) {
    this->textures.erase(name);
  }

  std::shared_ptr<sf::Texture> getTexture(std::string name) {
    if (this->textures.find(name) == this->textures.end()) {
      Log::err("Unable to find texture with name '", name, "'");
      throw std::runtime_error("Unable to find texture!");
    }
    return this->textures[name];
  }
};