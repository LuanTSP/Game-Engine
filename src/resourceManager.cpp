#include "../include/resourceManager.hpp"



void ResourceManager::loadTexture(std::string& name, std::string& path) {
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

void ResourceManager::loadTexture(const char* name, const char* path) {
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

void ResourceManager::unloadTexture(std::string name) {
  this->textures.erase(name);
}

std::shared_ptr<sf::Texture> ResourceManager::getTexture(std::string name) {
  if (this->textures.find(name) == this->textures.end()) {
    Log::err("Unable to find texture with name '", name, "'");
    throw std::runtime_error("Unable to find texture!");
  }
  return this->textures[name];
}
