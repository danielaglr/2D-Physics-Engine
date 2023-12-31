#pragma once

#include "Engine/engine.h"

#include "SDL.h"
#include "GLFW/glfw3.h"

#include <vector>
#include <chrono>

class Render {
public:

  void start();
  void renderLoop();
  void drawObjects();

  Render() : physEngine(new Engine()) {}

  Engine* physEngine;

private:

  SDL_Window* window;
  SDL_Renderer* renderer;

  int windowWidth = 1080;
  int windowHeight = 720;
};