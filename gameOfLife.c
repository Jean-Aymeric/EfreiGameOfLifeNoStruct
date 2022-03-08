//
// Created by JAD on 08/03/2022.
//

#include "gameOfLife.h"

short **createGrid(int width, int height) {
    short **grid;
    grid = (int **) malloc(sizeof(int *) * height);
    if (grid == NULL) {
        return NULL;
    }
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(width * sizeof(int));
    }
    return grid;
}

short destroyGrid(short** grid, int width, int height) {
    if ((width < 0) || (height < 0)) {
        return 0;
    }
    for (int i = 0; i < height; i++) {
        free(grid[i]);
    }
    free(grid);
    return 1;
}

short initializeGrid(short **grid, int width, int height) {
    srand(time(NULL));
    if ((width < 0) || (height < 0)) {
        return 0;
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = rand() % 2;
        }
    }
    return 1;
}

short displayGrid(short **grid, int width, int height) {
    if ((width < 0) || (height < 0)) {
        return 0;
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", grid[y][x] == 0 ? ' ' : '*');
        }
        printf("\n");
    }
    printf("\n");
    return 1;
}

int countLivingNeighboringCells(short **grid, int width, int height, int x, int y) {
    int livingNeighboringCells = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i != 0 && j != 0) {
                livingNeighboringCells += grid[(y + i + height) % height][(x + j + width) % width];
            }
        }
    }
    return livingNeighboringCells;
}

short goNextStep(short ***grid, int width, int height) {
    short** nextGrid = createGrid(width, height);
    if (nextGrid == NULL) {
        return 0;
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cellGoNextStep(*grid, nextGrid, width, height, x, y);
        }
    }
    destroyGrid(*grid, width, height);
    *grid = nextGrid;
    return 1;
}

void cellGoNextStep(short **grid, short **nextGrid, int width, int height, int x, int y) {
    if (countLivingNeighboringCells(grid, width, height, x, y) < 3) {
        nextGrid[y][x] = 0;
    } else {
        nextGrid[y][x] = grid[y][x];
    }
}