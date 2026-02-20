#include "inputHandler.h"

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_mouse.h>
#include <SDL3/SDL_render.h>

InputHandler::InputHandler() 
{
}

Point InputHandler::poll(SDL_Event event) {
  return mouseInput(event);
}

Point InputHandler::mouseInput(SDL_Event event) {
  if(event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
    if(event.button.button == SDL_BUTTON_LEFT)
    {
      mSelMouseRow = event.button.x;
      mSelMouseCol = event.button.y;
    }
  }
  return {mSelMouseRow, mSelMouseCol};
}
