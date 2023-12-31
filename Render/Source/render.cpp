#include "render.h"
#include "Engine/engine.h"

void Render::start() {

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "Failed to initialize SDL2. Error: " << SDL_GetError() << std::endl;
    return;
  }

  Render::window = SDL_CreateWindow("Physics Render", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_OPENGL);
  if (!Render::window) {
    std::cerr << "Failed to create window. Error: " << SDL_GetError() << std::endl;
    return;
  }

  SDL_GLContext glContext = SDL_GL_CreateContext(Render::window);
  if (!glContext) {
    std::cerr << "Failed to create OpenGL context. Error: " << SDL_GetError() << std::endl;
  }
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, windowWidth, 0.0, windowHeight, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  renderLoop();

  SDL_DestroyWindow(Render::window);
  SDL_Quit();
}

void Render::renderLoop() {
  bool running = true;
  SDL_Event event;

  auto lastTime = std::chrono::high_resolution_clock::now();

  while (running) {

    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = currentTime - lastTime;
    double deltaTime = duration.count();

    drawObjects();
    physEngine->updateSim(deltaTime);

    lastTime = currentTime;

    if (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
          running = false;
          break;
        }
        break;
      case SDL_MOUSEBUTTONDOWN:
        if (event.button.button == SDL_BUTTON_LEFT) {
          std::cout << "Spawning an entity at x: " << event.button.x << " y: " << event.button.y << std::endl;

          physEngine->addEntity(
            Entity(
              Vector2D(event.button.x, windowHeight - event.button.y),
              Vector2D(0.0, 0.0),
              Vector2D(0.0, -ACCELERATION_TO_GRAVITY),
              1
            )
          );
        }
        break;
      };
    }
  }
}

void Render::drawObjects() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  for (const Entity& e : physEngine->entities) {
    glBegin(GL_QUADS);
    glColor3f(255.0, 255.0, 255.0);
    glVertex2f(e.position.x - 25.0, e.position.y - 25.0);
    glVertex2f(e.position.x + 25.0, e.position.y - 25.0);
    glVertex2f(e.position.x + 25.0, e.position.y + 25.0);
    glVertex2f(e.position.x - 25.0, e.position.y + 25.0);
    glEnd();
  }

  SDL_GL_SwapWindow(window);
}

int main(int argc, char* argv[]) {
  std::cout << "Running simple sim." << std::endl;

  Render physRender;
  physRender.start();

  return 0;
}