#define MAX_QUEUE 1000000

typedef struct {
    int x, y;
} Point;

int minimumObstacles(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int dist[m][n];
    memset(dist, 0x3f, sizeof(dist)); 
    dist[0][0] = 0;

    Point queue[MAX_QUEUE];
    int front = MAX_QUEUE / 2, back = MAX_QUEUE / 2; 
    queue[back++] = (Point){0, 0};

    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (front < back) {
        Point current = queue[front++];
        int cur_dist = dist[current.x][current.y];

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dirs[i][0];
            int ny = current.y + dirs[i][1];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                int new_dist = cur_dist + grid[nx][ny];
                if (new_dist < dist[nx][ny]) {
                    dist[nx][ny] = new_dist;
                    if (grid[nx][ny] == 1) {
                        queue[back++] = (Point){nx, ny}; 
                    } else {
                        queue[--front] = (Point){nx, ny};
                    }
                }
            }
        }
    }

    return dist[m - 1][n - 1];
}
