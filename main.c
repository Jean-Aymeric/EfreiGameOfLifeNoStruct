#include "gameOfLife.h"

int main() {
    short** grid = createGrid(GRID_WIDTH, GRID_HEIGHT);
    initializeGrid(grid, GRID_WIDTH, GRID_HEIGHT);
    displayGrid(grid, GRID_WIDTH, GRID_HEIGHT);
    for (;;) {
        getchar();
        goNextStep(&grid, GRID_WIDTH, GRID_HEIGHT);
        displayGrid(grid, GRID_WIDTH, GRID_HEIGHT);
    }
    return 0;
}
