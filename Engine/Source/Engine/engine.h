#pragma once

#include "vect.h"
#include "entity.h"

#include <iostream>
#include <vector>

#define ACCELERATION_TO_GRAVITY 9.8

class Engine {
public:
  Engine() {}
  ~Engine() {}

  void addEntity(Entity e);
  void applyForce(Entity &e, Vector2D force, float deltaTime);
  void applyForce(Vector2D force, float deltaTime);
  void updateSim(float deltaTime);
  void engineLog();

private:
  std::vector<Entity> entities;
};