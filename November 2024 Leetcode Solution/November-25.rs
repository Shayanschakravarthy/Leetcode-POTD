use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn sliding_puzzle(board: Vec<Vec<i32>>) -> i32 {
        let dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)];
        let goal = "123450";
        let mut start = String::new();

        for row in &board {
            for &num in row {
                start.push((num as u8 + b'0') as char);
            }
        }

        if start == goal {
            return 0;
        }

        let mut queue = VecDeque::new();
        let mut seen = HashSet::new();
        queue.push_back((start.clone(), 0));
        seen.insert(start.clone());

        while let Some((state, steps)) = queue.pop_front() {
            let zero_idx = state.find('0').unwrap();
            let x = zero_idx / 3;
            let y = zero_idx % 3;

            for &(dx, dy) in &dirs {
                let nx = x as i32 + dx;
                let ny = y as i32 + dy;

                if nx < 0 || nx >= 2 || ny < 0 || ny >= 3 {
                    continue;
                }

                let swap_idx = (nx * 3 + ny) as usize;

                let mut next_state: Vec<char> = state.chars().collect();
                next_state.swap(zero_idx, swap_idx);

                let next_state: String = next_state.into_iter().collect();

                if next_state == goal {
                    return steps + 1;
                }

                if seen.insert(next_state.clone()) {
                    queue.push_back((next_state, steps + 1));
                }
            }
        }

        -1
    }
}
