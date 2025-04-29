#include "components.hpp"

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

AngleComponent::AngleComponent(float angle) {
  this->angle = angle;
}

SpriteComponent::SpriteComponent(std::string& texturePath) {
  if (!this->texture.loadFromFile(texturePath)) {
    Log::err("Failed to load texture!");
    throw std::runtime_error("Failed to load texture!");
  }

  sprite.setTexture(this->texture);
}