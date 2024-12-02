impl Solution {
    pub fn is_prefix_of_word(sentence: String, search_word: String) -> i32 {
        sentence.split_whitespace()
            .enumerate()
            .find(|(_, word)| word.starts_with(&search_word))
            .map_or(-1, |(i, _)| (i + 1) as i32)
    }
}

2)
impl Solution {
    pub fn is_prefix_of_word(sentence: String, search_word: String) -> i32 {
        let mut word_index = 1;
        let n = sentence.len();
        let m = search_word.len();
        let chars: Vec<char> = sentence.chars().collect();
        let search_chars: Vec<char> = search_word.chars().collect();

        let mut i = 0;
        while i < n {
            if i + m <= n 
                && chars[i..i + m] == search_chars[..]
                && (i == 0 || chars[i - 1] == ' ') {
                return word_index as i32;
            }

            while i < n && chars[i] != ' ' {
                i += 1;
            }
            word_index += 1;
            i += 1; 
        }
        -1
    }
}
