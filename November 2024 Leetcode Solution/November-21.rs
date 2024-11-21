use std::collections::VecDeque;

impl Solution {
    pub fn count_unguarded(m: i32, n: i32, guards: Vec<Vec<i32>>, walls: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (m as usize, n as usize);
        let mut grid = vec![vec![0; n]; m];

        for guard in &guards {
            grid[guard[0] as usize][guard[1] as usize] = 2;
        }
        for wall in &walls {
            grid[wall[0] as usize][wall[1] as usize] = 2;
        }

        let directions = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        let mut queue = VecDeque::new();

        for guard in &guards {
            queue.push_back((guard[0] as usize, guard[1] as usize));
        }

        while let Some((x, y)) = queue.pop_front() {
            for &(dx, dy) in &directions {
                let (mut nx, mut ny) = (x as isize, y as isize);
                while {
                    nx += dx;
                    ny += dy;
                    nx >= 0 && nx < m as isize && ny >= 0 && ny < n as isize
                } {
                    let (ux, uy) = (nx as usize, ny as usize);
                    if grid[ux][uy] == 2 {
                        break; 
                    }
                    if grid[ux][uy] == 0 {
                        grid[ux][uy] = 1; 
                    }
                }
            }
        }

        grid.iter().flatten().filter(|&&cell| cell == 0).count() as i32
    }
}
