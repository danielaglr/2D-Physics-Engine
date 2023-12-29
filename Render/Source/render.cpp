#include "Engine/engine.h"

int main(int argc, char* argv[]) {
  std::cout << "Running simple sim." << std::endl;

  Engine physEngine;

  Entity e1(Vector2D(1, 1), Vector2D(0,0), Vector2D(0, 0), 1.0);
  Entity e2(Vector2D(2, 1), Vector2D(0, 0), Vector2D(1, 0), 2.0);

  physEngine.addEntity(e1);
  physEngine.addEntity(e2);

  for (int i = 0; i < 5; ++i) {
    physEngine.updateSim(1.0);
    physEngine.engineLog();
    std::cout << std::endl;
  }
}