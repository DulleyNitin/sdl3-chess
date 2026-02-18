#ifndef BOARD_H
#define BOARD_H

#include "grid.h"
#pragma once

class Board {
private:
  int mRows;
  int mCols;
  int mCellSize;
  Grid<int> mBoard;
public:
  Board(int, int, int);
  int getRows();
  int getCols();
  int getCellSize();
  point getWorldPostion(int, int);
  point getGridPosition(int, int);
};

#endif 
