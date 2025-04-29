#pragma once
#include <SFML/Graphics.hpp>
#include "entityManager.hpp"

/**
 * @brief Abstract base class representing a scene in the application.
 * 
 * A Scene encapsulates a set of entities, logic for input handling, updating, 
 * and rendering. Specific scenes (like Menu, Gameplay, GameOver, etc.) should
 * inherit from this class and implement the required virtual methods.
 */
class Scene {
  private:
  sf::RenderWindow* window;       // Pointer to the SFML RenderWindow where the scene is drawn.
  bool running = true;                    // Indicates whether the scene is active and running.
  /* TODO: ADD SUPPORT FOR ADDING AND RUNNING SYSTEMS */

  public:
  EntityManager* entityManager;   // Manages all entities and components in the scene.

  public:
  /**
   * @brief Constructs a new Scene.
   * 
   * Initializes the scene with a reference to the SFML render window.
   * 
   * @param window Pointer to the SFML RenderWindow where the scene will render its contents.
   */
  Scene(sf::RenderWindow* window) 
  : window(window) {
    this->entityManager = new EntityManager();
  }

  /**
   * @brief Virtual destructor.
   * 
   * Ensures proper cleanup when deleting derived scenes via a base class pointer.
   */
  virtual ~Scene() = default;

  /**
   * @brief Load and initialize the scene.
   * 
   * Derived scenes must implement this to set up entities, components, resources, etc.
   */
  virtual void load() = 0;

  virtual void handleEvents(sf::Event event) = 0;

  /**
   * @brief Update the scene logic.
   * 
   * Derived scenes must implement this to update game objects, physics, timers, etc.
   * 
   * @param dt The time elapsed (delta time) since the last frame, in seconds.
   */
  virtual void update() = 0;

  /**
   * @brief Render the scene contents.
   * 
   * Derived scenes must implement this to draw all visible elements onto the window.
   */
  void render() {};

  /**
   * @brief Check if the scene is still running.
   * 
   * Used to determine whether the scene should continue updating and rendering.
   * 
   * @return True if the scene is running, false if it has ended.
   */
  bool isRunning() { return this->running; }

  /**
   * @brief End the current scene.
   * 
   * Marks the scene as no longer running, signaling it should be exited or switched.
   */
  void end() { this->running = false; }

  /**
   * @brief Get a reference to the SFML window.
   * 
   * Allows derived scenes to access the render window for drawing operations.
   * 
   * @return A reference to the pointer to the SFML RenderWindow.
   */
  sf::RenderWindow*& getWindow() {
      return this->window;
  }
};
