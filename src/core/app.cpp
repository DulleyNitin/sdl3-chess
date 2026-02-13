#include "app.h"

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_render.h>

Application::Application() {
  mRunning = true;
  if(!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("video initialization failed!");
  }
  mWindow = SDL_CreateWindow("chess", 600, 600, SDL_WINDOW_RESIZABLE);
  if(!mWindow) {
    SDL_Log("window creation failed");
  }
  mRenderer = SDL_CreateRenderer(mWindow, NULL);
  if(!mRenderer) {
    SDL_Log("renderer creation failed");
  }
}

Application::~Application() {
  if(mRenderer) {
    SDL_DestroyRenderer(mRenderer);
  }
  if(mWindow) {
    SDL_DestroyWindow(mWindow);
  }
  SDL_QuitSubSystem(SDL_INIT_VIDEO);
  SDL_Quit();
}

void Application::input() {

}

void Application::update() {
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    if(event.type == SDL_EVENT_QUIT) {
      mRunning = false;
    }
  }
}

void Application::render() {

}

void Application::tick() {
  input();
  update();
  render();
}

void Application::mainLoop() {
  while(mRunning) {
    tick();
  }
}
