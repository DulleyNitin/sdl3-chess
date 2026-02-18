#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>

#include "../rendering/boardRenderer.h"

class Application {
private:
  bool mRunning;
public:
  SDL_Window *mWindow;
  SDL_Renderer *mRenderer;
  BoardRenderer mBoardRenderer;
  Application();
  ~Application();
  void input();
  void update();
  void render();
  void tick(float);
  void mainLoop();
};

#endif

