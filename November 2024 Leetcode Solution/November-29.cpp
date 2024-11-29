class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0);
        visited[0][0] = true;

        while (!pq.empty()) {
            auto [time, row, col] = pq.top();
            pq.pop();

            for (auto [dr, dc] : directions) {
                int newRow = row + dr, newCol = col + dc;
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !visited[newRow][newCol]) {
                    int newTime = time + 1;
                    if (grid[newRow][newCol] > newTime)
                        newTime += (grid[newRow][newCol] - newTime + 1) / 2 * 2;

                    if (newRow == rows - 1 && newCol == cols - 1)
                        return newTime;

                    visited[newRow][newCol] = true;
                    pq.emplace(newTime, newRow, newCol);
                }
            }
        }

        return -1;
    }
};
