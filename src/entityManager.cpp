#include "../include/entityManager.hpp"


EntityManager::EntityManager() {};

void EntityManager::update() {
  // Remove all entities marked to be removed
  for (auto id : toRemove) {
    removeEntity(id);
  }
  toRemove.clear();
}

std::size_t EntityManager::createEntity(std::string tag) {
  nextId++;
  tags[nextId] = tag;
  return nextId;
}

std::string EntityManager::getTag(std::size_t id) const {
  auto it = tags.find(id);
  if (it != tags.end()) {
    return it->second;
  }
  Log::err("Invalid id!");
  throw std::runtime_error("Invalid Id!");
}

void EntityManager::removeEntity(std::size_t id) {
  // Erase all components of entity from 'components'
  for (auto &[type, map] : components) {
    map.erase(id);
  }

  this->removed.push_back(id);

  // Erase from tags
  tags.erase(id);
}

void EntityManager::removeEntitiesByTag(std::string tag) {
  for (auto [id, e_tag] : tags) {
    if (e_tag == tag) {
      toRemove.push_back(id);
    }
  }
}