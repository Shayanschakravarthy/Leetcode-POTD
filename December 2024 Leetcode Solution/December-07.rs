impl Solution {
    pub fn minimum_size(nums: Vec<i32>, max_operations: i32) -> i32 {
        fn can_divide(nums: &Vec<i32>, max_size: i32, max_operations: i32) -> bool {
            nums.iter()
                .map(|&num| (num - 1) / max_size)
                .sum::<i32>() <= max_operations
        }

        let (mut left, mut right) = (1, *nums.iter().max().unwrap());

        while left < right {
            let mid = left + (right - left) / 2;
            if can_divide(&nums, mid, max_operations) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        left
    }
}
