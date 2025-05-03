#pragma once
#include <SFML/Graphics.hpp>
#include <memory>


sf::Vector2f getCenterPos(sf::RenderWindow& window) {  
  auto size = window.getSize();
  
  sf::Vector2f center;
  center.x = size.x / 2.0f;
  center.y = size.y / 2.0f;

  return center;
}