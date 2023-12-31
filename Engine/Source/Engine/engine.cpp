#include "engine.h"

void Engine::addEntity(Entity e) {
  entities.push_back(e);
}

void Engine::applyForce(Entity &e, Vector2D force, float deltaTime) {
  e.acceleration.x = force.x / e.mass;
  e.acceleration.y = force.y / e.mass;

  e.velocity.x += e.acceleration.x * deltaTime;
  e.velocity.y += e.acceleration.y * deltaTime;

  e.position.x += e.velocity.x * deltaTime;
  e.position.y += e.velocity.y * deltaTime;
}

void Engine::applyForce(Vector2D force, float deltaTime) {
  for (Entity &e : entities) {
    e.acceleration.x = force.x / e.mass;
    e.acceleration.y = force.y / e.mass;

    e.velocity.x += e.acceleration.x * deltaTime;
    e.velocity.y += e.acceleration.y * deltaTime;

    e.position.x += e.velocity.x * deltaTime;
    e.position.y += e.velocity.y * deltaTime;
  }
}

void Engine::updateSim(float deltaTime) {
  for (Entity &e : entities) {
    e.velocity.x += e.acceleration.x * deltaTime;
    e.velocity.y += e.acceleration.y * deltaTime;

    e.position.x += e.velocity.x * deltaTime;
    e.position.y += e.velocity.y * deltaTime;
  }
}

void Engine::engineLog() {

  for (const Entity& e : entities) {
    std::cout << "Entity [" << std::endl;
    std::cout << "Position: (" << e.position.x << ", " << e.position.y << ")" << std::endl;
    std::cout << "Velocity: (" << e.velocity.x << ", " << e.velocity.y << ")" << std::endl;
    std::cout << "Acceleration: (" << e.acceleration.x << ", " << e.acceleration.y << ")" << std::endl;
    std::cout << "]" << std::endl;
  }
}