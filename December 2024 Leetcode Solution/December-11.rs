impl Solution {
    pub fn maximum_beauty(nums: Vec<i32>, k: i32) -> i32 {
        let max_flower = *nums.iter().max().unwrap();
        let max_range = (max_flower + k * 2 + 1) as usize;
        let mut prefix_sum = vec![0; max_range + 1];

        for &flower in &nums {
            prefix_sum[flower as usize] += 1;
            if (flower + k * 2 + 1) as usize <= max_range {
                prefix_sum[(flower + k * 2 + 1) as usize] -= 1;
            }
        }

        let mut max_beauty = 0;
        let mut running_sum = 0;
        for value in prefix_sum {
            running_sum += value;
            max_beauty = max_beauty.max(running_sum);
        }

        max_beauty
    }
}
