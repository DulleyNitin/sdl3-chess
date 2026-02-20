#ifndef INPUT_HANDLER
#define INPUT_HANDLER
#pragma once

#include <SDL3/SDL_events.h>
#include "../utils/point.h"

class InputHandler {
  int mSelMouseRow; //will store the selected row when mouse is clicked on it
  int mSelMouseCol;
public: 
  InputHandler();
  Point poll(SDL_Event); //to call every event handler
  Point mouseInput(SDL_Event);
};

#endif // !INPUT_HANDLER
