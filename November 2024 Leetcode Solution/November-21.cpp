class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<int> grid(m * n, 0); 
        auto index = [&](int x, int y) { return x * n + y; }; 

        for (const auto& guard : guards) grid[index(guard[0], guard[1])] = 2;
        for (const auto& wall : walls) grid[index(wall[0], wall[1])] = 2;

        const int dirs[5] = {-1, 0, 1, 0, -1};

        for (const auto& guard : guards) {
            for (int d = 0; d < 4; ++d) {
                int x = guard[0], y = guard[1];
                int dx = dirs[d], dy = dirs[d + 1];
                while (true) {
                    x += dx;
                    y += dy;

                    if (x < 0 || x >= m || y < 0 || y >= n || grid[index(x, y)] == 2) break;

                    if (grid[index(x, y)] == 0) grid[index(x, y)] = 1;
                }
            }
        }

        return count(grid.begin(), grid.end(), 0);
    }
};
