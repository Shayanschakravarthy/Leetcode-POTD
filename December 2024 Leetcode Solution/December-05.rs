impl Solution {
    pub fn can_change(start: String, target: String) -> bool {
        let n = start.len();
        let (mut i, mut j) = (0, 0);
        let start_chars: Vec<char> = start.chars().collect();
        let target_chars: Vec<char> = target.chars().collect();

        while i < n {
            if start_chars[i] != '_' {
                while j < n && target_chars[j] == '_' {
                    j += 1;
                }

                if j == n || start_chars[i] != target_chars[j] {
                    return false;
                }

                if (start_chars[i] == 'L' && i < j) || (start_chars[i] == 'R' && i > j) {
                    return false;
                }

                j += 1;
            }
            i += 1;
        }

        while j < n {
            if target_chars[j] != '_' {
                return false;
            }
            j += 1;
        }

        true
    }
}
