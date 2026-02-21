#ifndef BOARD_RENDERER_H
#define BOARD_RENDERER_H

#include "../board/board.h"
#include <SDL3/SDL_render.h>

class BoardRenderer {
public:
  BoardRenderer();
  ~BoardRenderer();
  void drawBoard(SDL_Renderer*, Board*);
};

#endif 
