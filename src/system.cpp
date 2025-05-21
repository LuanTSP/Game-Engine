#include "../include/system.hpp"


System::System(std::shared_ptr<sf::RenderWindow>& window, std::shared_ptr<EntityManager>& entityManager) :
  window(window),
  entityManager(entityManager)
{}

