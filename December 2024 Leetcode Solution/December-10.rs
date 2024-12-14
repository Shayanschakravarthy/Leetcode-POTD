impl Solution {
    pub fn maximum_length(s: String) -> i32 {
        fn is_valid(s: &str, n: usize, x: usize) -> bool {
            let mut freq = vec![0; 26];
            let bytes = s.as_bytes();
            let mut i = 0;
            while i < n {
                let mut j = i + 1;
                while j < n && bytes[j] == bytes[i] {
                    j += 1;
                }
                let index = (bytes[i] - b'a') as usize;
                freq[index] += (j - i).saturating_sub(x - 1);
                if freq[index] >= 3 {
                    return true;
                }
                i = j;
            }
            false
        }

        let n = s.len();
        let mut l = 0;
        let mut r = n;
        while l < r {
            let mid = (l + r + 1) / 2;
            if is_valid(&s, n, mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if l == 0 { -1 } else { l as i32 }
    }
}
