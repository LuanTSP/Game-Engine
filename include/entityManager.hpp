#pragma once
#include <unordered_map>
#include <unordered_set>
#include "components.hpp"
#include "log.hpp"
#include <typeindex>
#include <memory>
#include <string>
#include <vector>

class EntityManager {
  private:
  // Id to be used in the creation of the next entity
  std::size_t nextId = 0;
  
  // Map of the components by type of component
  // Get the component by the type and the entity id
  // 
  // Example:
  // entityComponents[std::type_index(typeid(Health)), 2] # Get the health component from the health section with id 2
  std::unordered_map< 
    std::type_index, 
    std::unordered_map<std::size_t, std::shared_ptr<Component>>
  > components; 

  // Map of tags
  std::unordered_map<std::size_t, std::string> tags; 

  // Entities to remove next frame
  std::vector<std::size_t> toRemove;

  public:
  /**
  * @brief Constructs a new EntityManager.
  * 
  * Initializes an empty manager ready to create entities and manage their components.
  */
  EntityManager() {};

  /**
  * @brief Updates the EntityManager by removing all entities marked for deletion.
  * 
  * This function iterates over the list of entities scheduled for removal,
  * deletes them from the system, and then clears the removal list.
  * Should be called once per frame or at a safe point where entities can be cleaned up.
  */
  void Update() {
    // Remove all entities marked to be removed
    for (auto e : toRemove) {
      removeEntity(e);
    }
    toRemove.clear();
  }

  /**
  * @brief Creates a new entity with a given tag.
  * 
  * Increments the internal entity ID counter, assigns the provided tag to the new entity,
  * and returns the unique ID associated with it. 
  * 
  * @param tag A string representing the tag or category of the entity (e.g., "Player", "Enemy").
  * @return The unique ID assigned to the newly created entity.
  */
  std::size_t createEntity(std::string tag) {
    nextId++;
    tags[nextId] = tag;
    return nextId;
  }

  /**
  * @brief Retrieves the tag associated with a given entity ID.
  * 
  * Searches for the entity ID in the internal tag mapping and returns the corresponding tag.
  * If the entity ID is not found, logs an error and throws a runtime exception.
  * 
  * @param id The unique ID of the entity whose tag is being requested.
  * @return The tag (as a string) associated with the specified entity ID.
  * @throws std::runtime_error if the given entity ID does not exist.
  */
  std::string getTag(std::size_t id) const {
    auto it = tags.find(id);
    if (it != tags.end()) {
      return it->second;
    }
    Log::err("Invalid id!");
    throw std::runtime_error("Invalid Id!");
  }

  /**
  * @brief Adds a component of type T to the entity with the given ID.
  * 
  * This function constructs a new component of type T using the provided arguments 
  * and associates it with the specified entity ID. The component is stored in a 
  * type-safe map structure, allowing later retrieval by type and entity ID.
  * 
  * @tparam T The type of the component to add (must inherit from Component).
  * @tparam Args The types of the arguments used to construct the component.
  * @param id The ID of the entity to which the component will be attached.
  * @param args The arguments to forward to T's constructor.
  */
  template <typename T, typename... Args>
  void addComponent(std::size_t id, Args&&... args) {
    components[std::type_index(typeid(T))][id] = std::make_shared<T>(std::forward<Args>(args)...);
  }

  template<typename T>
  std::shared_ptr<T> getComponent(std::size_t id) {
    // Retrieves a pointer to the component if found, else returns a nullptr
    //
    // Example:
    // std::shred_pointer<Health> health = entityManager.getComponent<Health>(id);

    auto& compMap = components[std::type_index(typeid(T))];
    auto it = compMap.find(id);
    if (it != compMap.end()) {
      return std::static_pointer_cast<T>(it->second);
    }
    return nullptr;
  }

  /**
  * @brief Retrieves a component of type T associated with a given entity ID.
  * 
  * Searches for a component of the specified type T attached to the given entity ID.
  * If found, returns a shared pointer to the component. If not found, returns a nullptr.
  * 
  * @tparam T The type of the component to retrieve.
  * @param id The unique ID of the entity whose component is being requested.
  * @return A shared pointer to the component of type T, or nullptr if the component does not exist.
  */
  template<typename T>
  std::unordered_map<std::size_t, std::shared_ptr<T>>& getAllComponents() {
    auto& compMap = components[std::type_index(typeid(T))];
    return *reinterpret_cast<std::unordered_map<std::size_t, std::shared_ptr<T>>*>(&compMap);
  }

  /**
  * @brief Checks whether an entity has a component of a specific type T.
  * 
  * Searches for a component of the specified type T attached to the given entity ID.
  * Returns true if the component exists, or false otherwise.
  * 
  * @tparam T The type of the component to check for.
  * @param id The unique ID of the entity to check.
  * @return True if the entity has the component of type T, false if it does not.
  */
  template<typename T>
  bool hasComponent(std::size_t id) {
    auto& compMap = components[std::type_index(typeid(T))];
    auto it = compMap.find(id);
    if (it != compMap.end()) return true;
    return false;
  }

  /**
  * @brief Removes a component of type T from an entity.
  * 
  * Deletes the component of the specified type T associated with the given entity ID.
  * The component is erased from the internal component storage.
  * 
  * @tparam T The type of the component to remove.
  * @param id The unique ID of the entity whose component is to be removed.
  */
  template<typename T>
  void removeComponent(std::size_t id) {
    // Remove the component from 'components'
    components[std::type_index(typeid(T))].erase(id);
  }

  /**
  * @brief Removes an entity and all its associated components from the system.
  * 
  * This function erases the entity with the given ID from both the component storage 
  * and the tag map. All components associated with the entity are also removed.
  * 
  * @param id The unique ID of the entity to be removed.
  */
  void removeEntity(std::size_t id) {
    // Erase all components of entity from 'components'
    for (auto& [type, map] : components) {
      map.erase(id);
    }

    // Erase from tags
    tags.erase(id);
  }

  /**
  * @brief Marks entities with a specific tag for removal.
  * 
  * This function iterates through all entities and adds those with the given tag 
  * to the removal list. These entities will be removed when `Update()` is called.
  * 
  * @param tag The tag that identifies the entities to be removed.
  */  
  void removeEntitiesByTag(std::string tag) {
    for (auto [id, e_tag] : tags) {
      if (e_tag == tag) {
        toRemove.push_back(id);
      }
    }
  }
};