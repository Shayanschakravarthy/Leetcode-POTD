use std::collections::HashMap;

impl Solution {
    pub fn max_equal_rows_after_flips(matrix: Vec<Vec<i32>>) -> i32 {
        let mut count = HashMap::new();
        let mut max_count = 0;

        for row in matrix.iter() {
            let flip = row[0] == 1;
            let key: Vec<i32> = row.iter()
                                   .map(|&num| if flip { 1 - num } else { num })
                                   .collect();

            *count.entry(key.clone()).or_insert(0) += 1;
            max_count = max_count.max(*count.get(&key).unwrap());
        }

        max_count
    }
} 
