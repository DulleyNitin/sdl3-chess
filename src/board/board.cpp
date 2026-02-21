#include "board.h"
#include <SDL3/SDL_log.h>

Board::Board(int row, int col, int cellSize) 
  :mRows(row),
   mCols(col),
   mCellSize(cellSize),
   mBoard(mRows, mCols, mCellSize),
   mClickedRow(-1),
   mClickedCol(-1)
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

Point Board::getWorldPostion(int row, int col) {
  return mBoard.gridToWorld(row, col);
}

Point Board::getGridPosition(int x, int y) {
  return mBoard.worldToGrid(x, y);
}

void Board::setSelect(int row, int col) {
  mClickedRow = row;
  mClickedCol = col;
}
