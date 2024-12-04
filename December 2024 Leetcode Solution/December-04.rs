impl Solution {
    pub fn can_make_subsequence(str1: String, str2: String) -> bool {
        let (mut j, m) = (0, str2.len());
        let str2_bytes = str2.as_bytes();
        for c in str1.bytes() {
            if j < m && (c == str2_bytes[j] || (c - b'a' + 1) % 26 + b'a' == str2_bytes[j]) {
                j += 1;
                if j == m {
                    return true;
                }
            }
        }
        j == m
    }
}
