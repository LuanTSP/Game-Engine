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
  PositionComponent(float x, float y);
};

class VelocityComponent : public Component {
public:
  float x;
  float y;

public:
  VelocityComponent(float x, float y);
};

class AccelerationComponent : public Component {
public:
  float x;
  float y;

public:
  AccelerationComponent(float x, float y);
};

class HealthComponent : public Component {
public:
  float max;
  float curr;

public:
  HealthComponent(float max, float curr);
};

class AngleComponent : public Component {
public:
  float angle;

public:
  AngleComponent(float angle);
};

class SpriteComponent : public Component {
public:
  sf::Sprite sprite;

  SpriteComponent(std::shared_ptr<sf::Texture> texture);
};
