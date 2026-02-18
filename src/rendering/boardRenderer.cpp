#include "boardRenderer.h"

#include <SDL3/SDL_log.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

BoardRenderer::BoardRenderer() 
  : mChessBoard(8, 8, 100)//mannually giving the parameters here for the board
{
  mChessBoardRows = mChessBoard.getRows();
  mChessBoardCols = mChessBoard.getCols();
}

BoardRenderer::~BoardRenderer() {

}

void BoardRenderer::drawBoard(SDL_Renderer *renderer) {
  int size = mChessBoard.getCellSize();
  for(int row = 0; row < mChessBoardRows; row++) {
    for( int col = 0; col < mChessBoardCols; col++) {
      point pos = mChessBoard.getWorldPostion(row, col);
      SDL_FRect cell = {
        static_cast<float>(pos.x), 
        static_cast<float>(pos.y), 
        static_cast<float>(size), 
        static_cast<float>(size)
      };
      if((row + col)%2 == 0) { //logic for alternating color of the squares
        SDL_SetRenderDrawColor(renderer, 118, 150, 86, SDL_ALPHA_OPAQUE);
      } else {
        SDL_SetRenderDrawColor(renderer, 238, 238, 210, SDL_ALPHA_OPAQUE);
      }
      SDL_RenderFillRect(renderer, &cell);
    }
  }
}

