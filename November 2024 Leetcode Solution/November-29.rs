use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn minimum_time(grid: Vec<Vec<i32>>) -> i32 {
        let directions = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        let rows = grid.len();
        let cols = grid[0].len();

        if grid[0][1] > 1 && grid[1][0] > 1 {
            return -1;
        }

        let mut visited = vec![vec![false; cols]; rows];
        let mut heap = BinaryHeap::new();
        heap.push(Reverse((0, 0, 0))); 
        visited[0][0] = true;

        while let Some(Reverse((time, row, col))) = heap.pop() {
            for &(dr, dc) in &directions {
                let new_row = row as isize + dr;
                let new_col = col as isize + dc;

                if new_row >= 0
                    && new_row < rows as isize
                    && new_col >= 0
                    && new_col < cols as isize
                    && !visited[new_row as usize][new_col as usize]
                {
                    let mut new_time = time + 1;
                    let (nr, nc) = (new_row as usize, new_col as usize);
                    if grid[nr][nc] > new_time {
                        new_time += (grid[nr][nc] - new_time + 1) / 2 * 2;
                    }

                    if nr == rows - 1 && nc == cols - 1 {
                        return new_time;
                    }

                    visited[nr][nc] = true;
                    heap.push(Reverse((new_time, nr, nc)));
                }
            }
        }

        -1
    }
}
