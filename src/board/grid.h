#ifndef GRID_H
#define GRID_H

#include <vector>

#include "../utils/point.h"
#pragma once

template<typename T> class Grid { //using templates so that this grid system can be reused for future projects....
private:
  std::vector<T> mCells; //flat vector for storing cells
  int mCellSize;
  int mRows;
  int mCols;
  const int getIndex(int row, int col) const{//this calculates the index
    return row * mCols + col;
  } 
public:
  Grid(int row, int col, int cellSize){
    mRows = row;
    mCols = col;
    mCellSize = cellSize;
    mCells.resize(row * col);
  }
  bool isValid(int row, int col) {
    if(getIndex(row, col) > (mRows*mCols)) {
      return false;
    }
    return true;
  }
  T& getCell(int row, int col){ //caller can modify via the reference of the cell
    if(isValid(row, col))
      return mCells[getIndex(row, col)];
    return nullptr;
  } 

  const T& getCell(int row, int col) const{ //one const version so that it can be read only
    if(isValid(row, col)) {
      return mCells[getIndex(row, col)];
    }
    return nullptr;
  }
  const int getRows() const{
    return mRows;
  }
  const int getCols() const{
    return mCols;
  }
  const int getCellSize() const{
    return mCellSize;
  }
  const Point gridToWorld(int row, int col) const{//to translate the grid coordinates to pixel positions
    int x = col*mCellSize;
    int y = row*mCellSize;
    return Point{x, y};
  }
  const Point worldToGrid(int x, int y) const{//to translate the pixel positions to grid coordinates
    int row = y/mCellSize;
    int col = x/mCellSize;
    return Point{row, col};
  }
};

#endif 
