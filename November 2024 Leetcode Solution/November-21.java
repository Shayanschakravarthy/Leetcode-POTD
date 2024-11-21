class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {

        int[][] grid = new int[m][n];

        for (int[] guard : guards) grid[guard[0]][guard[1]] = 2;
        for (int[] wall : walls) grid[wall[0]][wall[1]] = 2;

        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int[] guard : guards) {
            for (int[] dir : dirs) {
                int x = guard[0] + dir[0], y = guard[1] + dir[1];
                while (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 2) {
                    if (grid[x][y] == 0) grid[x][y] = 1; 
                    x += dir[0];
                    y += dir[1];
                }
            }
        }

        int unguardedCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) unguardedCount++;
            }
        }

        return unguardedCount;
    }
}
