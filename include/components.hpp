#pragma once
#include <SFML/Graphics.hpp>
#include "resourceManager.hpp"

class Component {
public:
  virtual ~Component() = default;
};

class PositionComponent : public Component {
public:
  float x;
  float y;

public:
  PositionComponent(float x, float y) {
    this->x = x;
    this->y = y;
  }
};

class VelocityComponent : public Component {
public:
  float x;
  float y;

public:
  VelocityComponent(float x, float y) {
    this->x = x;
    this->y = y;
  }
};

class AccelerationComponent : public Component {
public:
  float x;
  float y;

public:
  AccelerationComponent(float x, float y) {
    this->x = x;
    this->y = y;
  }
};

class HealthComponent : public Component {
public:
  float max;
  float curr;

public:
  HealthComponent(float max, float curr) {
    this->max = max;
    this->curr = curr;
  }
};

class AngleComponent : public Component {
public:
  float angle;

public:
  AngleComponent(float angle) { this->angle = angle; }
};

class StaticSpriteComponent : public Component {
public:
  sf::Sprite sprite;

  StaticSpriteComponent(std::shared_ptr<sf::Texture> texture) {
    sprite.setTexture(*texture);
    // set origin to center
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
  }
};

class AnimatedSpriteComponent : public Component {
  public:
  float elapsed = 0;
  sf::Sprite sprite;
  int frameWidth;
  int frameHeight;
  int numFrames;
  float frameDuration;
  int currentFrame = 0;

  AnimatedSpriteComponent(
    std::shared_ptr<sf::Texture> texture,
    int frameWidth, 
    int frameHeight, 
    int numFrames, 
    float frameDuration,
    int currentFrame
  ) {
    this->frameWidth = frameWidth;
    this->frameHeight = frameHeight;
    this->numFrames = numFrames;
    this->frameDuration = frameDuration;
    this->currentFrame = currentFrame % numFrames;
    sprite.setTexture(*texture);
    sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
    // set origin to center
    sprite.setOrigin(this->frameWidth / 2.f, this->frameHeight / 2.f);
  };
};

class ScaleAnimatedSpriteComponent : public Component {
  public:
  float x;
  float y;

  ScaleAnimatedSpriteComponent(float x, float y) {
    this->x = x;
    this->y = y;
  }
};