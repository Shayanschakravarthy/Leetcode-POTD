int countUnguarded(int m, int n, int** guards, int guardsSize, int* guardsColSize, int** walls, int wallsSize, int* wallsColSize) {
    int* grid = (int*)calloc(m * n, sizeof(int));
    int index(int x, int y) { return x * n + y; }

    for (int i = 0; i < guardsSize; ++i) grid[index(guards[i][0], guards[i][1])] = 2;
    for (int i = 0; i < wallsSize; ++i) grid[index(walls[i][0], walls[i][1])] = 2;

    int dirs[5] = {-1, 0, 1, 0, -1};

    for (int i = 0; i < guardsSize; ++i) {
        for (int d = 0; d < 4; ++d) {
            int x = guards[i][0], y = guards[i][1];
            int dx = dirs[d], dy = dirs[d + 1];
            while (x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n && grid[index(x + dx, y + dy)] != 2) {
                x += dx;
                y += dy;
                if (grid[index(x, y)] == 0) grid[index(x, y)] = 1;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < m * n; ++i) if (grid[i] == 0) count++;
    free(grid);
    return count;
}
