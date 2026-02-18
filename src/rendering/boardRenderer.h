#ifndef BOARD_RENDERER_H
#define BOARD_RENDERER_H

#include "../board/board.h"
#include <SDL3/SDL_render.h>

class BoardRenderer {
private:
  Board mChessBoard;
  int mChessBoardRows; // contains the number of the rows and coloms in the board
  int mChessBoardCols;
public:
  BoardRenderer();
  ~BoardRenderer();
  void drawBoard(SDL_Renderer*);
};

#endif 
