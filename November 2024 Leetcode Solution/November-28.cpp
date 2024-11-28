class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        
        deque<pair<int, int>> q;
        q.push_back({0, 0});
        
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop_front();
            int cur_dist = dist[i][j];
            
            if (i == m - 1 && j == n - 1) {
                return cur_dist;
            }
            
            for (auto& [dx, dy] : dirs) {
                int x = i + dx, y = j + dy;
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int new_dist = cur_dist + grid[x][y];
                    if (new_dist < dist[x][y]) {
                        dist[x][y] = new_dist;
                        if (grid[x][y] == 1) {
                            q.push_back({x, y});
                        } else {
                            q.push_front({x, y});
                        }
                    }
                }
            }
        }
        
        return dist[m - 1][n - 1] != INT_MAX ? dist[m - 1][n - 1] : -1;
    }
};
