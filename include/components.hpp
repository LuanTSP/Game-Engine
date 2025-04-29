#pragma once

class Component {
  public:
  virtual ~Component() = default;
};

class Position : public Component {
  public:
  float x;
  float y;

  public:
  Position(float x, float y);
};

class Velocity : public Component {
  public:
  float x;
  float y;

  public:
  Velocity(float x, float y);
};

class Acceleration : public Component {
  public:
  float x;
  float y;

  public:
  Acceleration(float x, float y);
};

class Health : public Component {
  public:
  float max;
  float curr;

  public:
  Health(float max, float curr);
};

class Angle : public Component {
  public:
  float angle;

  public:
  Angle(float angle);
};
