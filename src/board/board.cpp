#include "board.h"
#include <SDL3/SDL_log.h>

Board::Board(int row, int col, int cellSize) 
  :mRows(row), mCols(col), mCellSize(cellSize), mBoard(mRows, mCols, mCellSize)
{
}

int Board::getRows() {
  return mBoard.getRows();
}

int Board::getCols() {
  return mBoard.getCols();
}

int Board::getCellSize() {
  return mBoard.getCellSize();
}

point Board::getWorldPostion(int row, int col) {
  return mBoard.gridToWorld(row, col);
}

