//
// Created by JAD on 08/03/2022.
//
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifndef GAMEOFLIFE_GAMEOFLIFE_H
#define GAMEOFLIFE_GAMEOFLIFE_H

#define GRID_WIDTH 110
#define GRID_HEIGHT 5

short** createGrid(int width, int height);
short destroyGrid(short** grid, int width, int height);
short initializeGrid(short** grid, int width, int height);
short displayGrid(short** grid, int width, int height);

int countLivingNeighboringCells(short** grid, int width, int height, int x, int y);
short goNextStep(short*** grid, int width, int height);
void cellGoNextStep(short** grid, short** nextGrid, int width, int height, int x, int y);


#endif //GAMEOFLIFE_GAMEOFLIFE_H
