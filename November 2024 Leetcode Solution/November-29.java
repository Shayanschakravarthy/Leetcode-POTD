class Solution {
    public int minimumTime(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        boolean[][] visited = new boolean[rows][cols];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        pq.offer(new int[]{0, 0, 0});
        visited[0][0] = true;

        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int time = curr[0], row = curr[1], col = curr[2];

            for (int[] dir : directions) {
                int newRow = row + dir[0], newCol = col + dir[1];
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !visited[newRow][newCol]) {
                    int newTime = time + 1;
                    if (grid[newRow][newCol] > newTime)
                        newTime += (grid[newRow][newCol] - newTime + 1) / 2 * 2;

                    if (newRow == rows - 1 && newCol == cols - 1)
                        return newTime;

                    visited[newRow][newCol] = true;
                    pq.offer(new int[]{newTime, newRow, newCol});
                }
            }
        }

        return -1;
    }
}
