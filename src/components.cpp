#include "../include/components.hpp"
#include "../include/log.hpp"

PositionComponent::PositionComponent(float x, float y) {
  this->x = x;
  this->y = y;
}

VelocityComponent::VelocityComponent(float x, float y) {
  this->x = x;
  this->y = y;
}

AccelerationComponent::AccelerationComponent(float x, float y) {
  this->x = x;
  this->y = y;
}

HealthComponent::HealthComponent(float curr, float max) {
  this->max = max;
  this->curr = curr;
}

AngleComponent::AngleComponent(float angle) { this->angle = angle; }

SpriteComponent::SpriteComponent(std::shared_ptr<sf::Texture> texture) {

  sprite.setTexture(*texture);
  sprite.setOrigin(0,0);
}
