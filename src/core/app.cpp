#include "app.h"

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_mouse.h>

Application::Application() 
  : mBoardRenderer()
{
  mRunning = true;
  if(!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("video initialization failed!");
  }
  mWindow = SDL_CreateWindow("chess", 800, 800, SDL_WINDOW_RESIZABLE);
  if(!mWindow) {
    SDL_Log("window creation failed");
  }
  mRenderer = SDL_CreateRenderer(mWindow, nullptr);
  if(!mRenderer) {
    SDL_Log("renderer creation failed");
  }
  SDL_SetRenderLogicalPresentation(mRenderer, 800, 800, SDL_LOGICAL_PRESENTATION_LETTERBOX);
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
    float x, y;
    SDL_MouseButtonFlags mouse = SDL_GetMouseState(&x, &y);
    SDL_Log("x: %f, y: %f", x, y);
  }
}

void Application::render() {
  SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(mRenderer);
  mBoardRenderer.drawBoard(mRenderer);
  SDL_RenderPresent(mRenderer);
}

void Application::tick(float dt) {
  input();
  update();
  render();
}

void Application::mainLoop() {
  const float targetFrameTime = 1.f/60.f; //target frame is 60 frames per second
  unsigned int lastTickTime = SDL_GetTicks(), startFrameTime, endFrameTime;
  unsigned int currentTime, lastTime = 0;// to get the fps
  int fps=0; //temporary to calculate the fps
  while(mRunning) {
    startFrameTime = SDL_GetTicks();
    float dt = (startFrameTime - lastTickTime) / 1000.f; //delta time
    lastTickTime = startFrameTime;

    if(dt > 0.05f) {
      dt = 0.05f;
    }
    tick(dt);
    endFrameTime = SDL_GetTicks();
    float frameTime = (endFrameTime - startFrameTime) / 1000.f;
    if(frameTime < targetFrameTime) {
      SDL_Delay( (targetFrameTime-frameTime) * 1000.f);
    }
    fps++;
    currentTime = SDL_GetTicks();
    if( currentTime > lastTime+1000 ) {
      lastTime = currentTime;
      SDL_Log("fps = %d", fps);
      fps = 0;
    }
    
  }
}
