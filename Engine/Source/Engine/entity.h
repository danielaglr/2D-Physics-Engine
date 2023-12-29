#pragma once

#include "vect.h"

struct Entity {
  Vector2D position;
  Vector2D velocity;
  Vector2D acceleration;
  float mass;

  Entity() : position(0.0, 0.0), velocity(0.0, 0.0), acceleration(0.0, 0.0), mass(1) {}
  Entity(Vector2D pos, Vector2D vel, Vector2D acc, float m) : position(pos), velocity(vel), acceleration(acc), mass(m) {}
};