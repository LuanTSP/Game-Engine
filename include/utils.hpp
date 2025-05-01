#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

sf::Vector2i getWindowCenterPos(sf::RenderWindow& window) {
  auto size = window.getSize();
  return sf::Vector2i(size.x / 2, size.y / 2);
}

sf::Vector2f getCenterPos(sf::RenderWindow& window, sf::Sprite& sprite) {
  auto bounds = sprite.getLocalBounds();
        
  float spriteWidth = bounds.width;
  float spriteHeight = bounds.height; 
  
  auto windowCenter = getWindowCenterPos(window);
  
  sf::Vector2f center;
  center.x = windowCenter.x - spriteWidth / 2.0f;
  center.y = windowCenter.y - spriteHeight / 2.0f;

  return center;
}