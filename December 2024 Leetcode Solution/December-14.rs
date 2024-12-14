impl Solution {
    pub fn continuous_subarrays(nums: Vec<i32>) -> i64 {
        let mut start = 0;
        let mut total_subarrays = 0i64;
        let mut max_deque: std::collections::VecDeque<usize> = std::collections::VecDeque::new();
        let mut min_deque: std::collections::VecDeque<usize> = std::collections::VecDeque::new();
        for (end, &num) in nums.iter().enumerate() {
            while let Some(&last) = max_deque.back() {
                if nums[last] <= num {
                    max_deque.pop_back();
                } else {
                    break;
                }
            }
            max_deque.push_back(end);
            while let Some(&last) = min_deque.back() {
                if nums[last] >= num {
                    min_deque.pop_back();
                } else {
                    break;
                }
            }
            min_deque.push_back(end);
            while nums[*max_deque.front().unwrap()] - nums[*min_deque.front().unwrap()] > 2 {
                if *max_deque.front().unwrap() == start {
                    max_deque.pop_front();
                }
                if *min_deque.front().unwrap() == start {
                    min_deque.pop_front();
                }
                start += 1;
            }
            total_subarrays += (end - start + 1) as i64;
        }

        total_subarrays
    }
}
