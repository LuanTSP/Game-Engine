#pragma once
#include "components.hpp"
#include "log.hpp"
#include <memory>
#include <string>
#include <typeindex>
#include <unordered_map>
#include <vector>

class EntityManager {
private:
  // Id to be used in the creation of the next entity
  std::size_t nextId = 0;

  std::unordered_map<
      std::type_index,
      std::unordered_map<std::size_t, std::shared_ptr<Component>>>
      components;

  std::unordered_map<std::size_t, std::string> tags;

  std::vector<std::size_t> toRemove;

public:
  EntityManager() {};

  void update() {
    // Remove all entities marked to be removed
    for (auto e : toRemove) {
      removeEntity(e);
    }
    toRemove.clear();
  }

  std::size_t createEntity(std::string tag) {
    nextId++;
    tags[nextId] = tag;
    return nextId;
  }

  std::string getTag(std::size_t id) const {
    auto it = tags.find(id);
    if (it != tags.end()) {
      return it->second;
    }
    Log::err("Invalid id!");
    throw std::runtime_error("Invalid Id!");
  }

  template <typename T, typename... Args>
  void addComponent(std::size_t id, Args &&...args) {
    components[std::type_index(typeid(T))][id] =
        std::make_shared<T>(std::forward<Args>(args)...);
  }

  template <typename T> std::shared_ptr<T> getComponent(std::size_t id) {
    auto &compMap = components[std::type_index(typeid(T))];
    auto it = compMap.find(id);
    if (it != compMap.end()) {
      return std::static_pointer_cast<T>(it->second);
    }
    return nullptr;
  }

  template <typename T>
  std::unordered_map<std::size_t, std::shared_ptr<T>> &getAllComponents() {
    auto &compMap = components[std::type_index(typeid(T))];
    return *reinterpret_cast<
        std::unordered_map<std::size_t, std::shared_ptr<T>> *>(&compMap);
  }

  template <typename T> bool hasComponent(std::size_t id) {
    auto &compMap = components[std::type_index(typeid(T))];
    auto it = compMap.find(id);
    if (it != compMap.end())
      return true;
    return false;
  }

  template <typename T> void removeComponent(std::size_t id) {
    // Remove the component from 'components'
    components[std::type_index(typeid(T))].erase(id);
  }

  void removeEntity(std::size_t id) {
    // Erase all components of entity from 'components'
    for (auto &[type, map] : components) {
      map.erase(id);
    }

    // Erase from tags
    tags.erase(id);
  }

  void removeEntitiesByTag(std::string tag) {
    for (auto [id, e_tag] : tags) {
      if (e_tag == tag) {
        toRemove.push_back(id);
      }
    }
  }
};
