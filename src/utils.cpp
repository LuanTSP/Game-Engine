#include "../include/utils.hpp"


sf::Vector2f getCenterPos(std::shared_ptr<sf::RenderWindow>& window) {  
  auto size = window->getSize();
  
  sf::Vector2f center;
  center.x = size.x / 2.0f;
  center.y = size.y / 2.0f;

  return center;
}