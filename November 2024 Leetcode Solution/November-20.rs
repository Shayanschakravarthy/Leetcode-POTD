use std::collections::HashMap;

impl Solution {
    pub fn take_characters(s: String, k: i32) -> i32 {
        let n = s.len();
        let mut cnt: HashMap<char, i32> = HashMap::new();

        for c in s.chars() {
            *cnt.entry(c).or_insert(0) += 1;
        }

        if "abc".chars().any(|c| cnt.get(&c).unwrap_or(&0) < &k) {
            return -1;
        }

        let mut mx = 0;
        let mut j = 0;
        let s = s.as_bytes(); 

        for i in 0..n {
            let c = s[i] as char; 
            *cnt.get_mut(&c).unwrap() -= 1;

            while cnt.get(&c).unwrap() < &k {
                let c_left = s[j] as char;
                *cnt.get_mut(&c_left).unwrap() += 1;
                j += 1;
            }

            mx = mx.max(i - j + 1);
        }

        (n as i32) - (mx as i32)
    }
}
