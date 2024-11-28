class Solution {
    public int minimumObstacles(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] dist = new int[m][n];
        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        dist[0][0] = 0;
        
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[]{0, 0});
        
        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.isEmpty()) {
            int[] cell = q.poll();
            int i = cell[0], j = cell[1];
            int curDist = dist[i][j];
            
            if (i == m - 1 && j == n - 1) {
                return curDist;
            }
            
            for (int[] dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int newDist = curDist + grid[x][y];
                    if (newDist < dist[x][y]) {
                        dist[x][y] = newDist;
                        if (grid[x][y] == 1) {
                            q.offer(new int[]{x, y});
                        } else {
                            q.offerFirst(new int[]{x, y});
                        }
                    }
                }
            }
        }
        
        return dist[m - 1][n - 1] != Integer.MAX_VALUE ? dist[m - 1][n - 1] : -1;
    }
}
