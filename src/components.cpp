#include "components.hpp"

Position::Position(float x, float y) {
  this->x = x;
  this->y = y;
}

Velocity::Velocity(float x, float y) {
  this->x = x;
  this->y = y;
}

Acceleration::Acceleration(float x, float y) {
  this->x = x;
  this->y = y;
}

Health::Health(float curr, float max) {
  this->max = max;
  this->curr = curr;
}

Angle::Angle(float angle) {
  this->angle = angle;
}