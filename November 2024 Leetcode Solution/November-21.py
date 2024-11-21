class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:

        grid = [[0] * n for _ in range(m)]

        for x, y in guards:
            grid[x][y] = 2
        for x, y in walls:
            grid[x][y] = 2

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        for x, y in guards:
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                while 0 <= nx < m and 0 <= ny < n and grid[nx][ny] != 2:
                    if grid[nx][ny] == 0:  
                        grid[nx][ny] = 1
                    nx += dx
                    ny += dy

        return sum(cell == 0 for row in grid for cell in row)
