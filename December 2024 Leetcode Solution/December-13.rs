impl Solution {
    pub fn find_score(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        let mut indexed_nums: Vec<(i32, usize)> = nums.into_iter().enumerate().map(|(i, x)| (x, i)).collect();
        indexed_nums.sort_unstable();

        let mut vis = vec![false; n];
        let mut ans: i64 = 0;

        for (val, idx) in indexed_nums {
            if !vis[idx] {
                ans += val as i64;
                vis[idx] = true;
                if idx > 0 {
                    vis[idx - 1] = true;
                }
                if idx + 1 < n {
                    vis[idx + 1] = true;
                }
            }
        }

        ans
    }
}
