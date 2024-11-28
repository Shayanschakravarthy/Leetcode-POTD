use std::collections::VecDeque;
impl Solution {
    pub fn minimum_obstacles(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut dist = vec![vec![i32::MAX; n]; m];
        dist[0][0] = 0;
        let mut q = VecDeque::new();
        q.push_back((0, 0)); 
        let dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)];
        while let Some((i, j)) = q.pop_front() {
            let cur_dist = dist[i][j];
            if i == m - 1 && j == n - 1 {
                return cur_dist;
            }
            for &(dx, dy) in &dirs {
                let x = i as i32 + dx;
                let y = j as i32 + dy;
                if x >= 0 && x < m as i32 && y >= 0 && y < n as i32 {
                    let x = x as usize;
                    let y = y as usize;
                    let new_dist = cur_dist + grid[x][y];
                    if new_dist < dist[x][y] {
                        dist[x][y] = new_dist;
                        if grid[x][y] == 1 {
                            q.push_back((x, y)); 
                        } else {
                            q.push_front((x, y)); 
                        }
                    }
                }
            }
        }
        if dist[m - 1][n - 1] == i32::MAX {
            -1
        } else {
            dist[m - 1][n - 1]
        }
    }
}
