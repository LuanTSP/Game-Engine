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

  void loadTexture(std::string& name, std::string& path);

  void loadTexture(const char* name, const char* path);

  void unloadTexture(std::string name);

  std::shared_ptr<sf::Texture> getTexture(std::string name);
};