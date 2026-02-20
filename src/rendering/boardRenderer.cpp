#include "boardRenderer.h"

#include <SDL3/SDL_log.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

BoardRenderer::BoardRenderer() {
}

BoardRenderer::~BoardRenderer() {

}

void BoardRenderer::drawBoard(SDL_Renderer *renderer, Board *chessBoard) {
  float chessBoardRows = chessBoard->getRows();
  float chessBoardCols = chessBoard->getCols();
  int size = chessBoard->getCellSize();
  //draw the entire board first
  for(int row = 0; row < chessBoardRows; row++) {
    for( int col = 0; col < chessBoardCols; col++) {
      Point pos = chessBoard->getWorldPostion(row, col);
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

  //draw the clicked cell
  int row = chessBoard->mClickedRow;
  int col = chessBoard->mClickedCol;
  Point worldPos = chessBoard->getWorldPostion(row, col);

  SDL_FRect hoveredCell = {
    static_cast<float>(worldPos.x),
    static_cast<float>(worldPos.y),
    static_cast<float>(size),
    static_cast<float>(size)
  };
  SDL_SetRenderDrawColor(renderer, 186, 202, 68, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(renderer, &hoveredCell);
}

