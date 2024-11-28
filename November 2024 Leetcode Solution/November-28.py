
from collections import deque
from typing import List

class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dist = [[float('inf')] * n for _ in range(m)]
        dist[0][0] = 0
        
        q = deque([(0, 0)])
        
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        while q:
            i, j = q.popleft()
            cur_dist = dist[i][j]
            
            if i == m - 1 and j == n - 1:
                return cur_dist
            
            for dx, dy in dirs:
                x, y = i + dx, j + dy
                if 0 <= x < m and 0 <= y < n:
                    new_dist = cur_dist + grid[x][y]
                    if new_dist < dist[x][y]:
                        dist[x][y] = new_dist
                        if grid[x][y] == 1:
                            q.append((x, y)) 
                        else:
                            q.appendleft((x, y))  
        
        return dist[m - 1][n - 1] if dist[m - 1][n - 1] != float('inf') else -1
