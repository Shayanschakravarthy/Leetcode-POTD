impl Solution {
    pub fn add_spaces(s: String, spaces: Vec<i32>) -> String {
        let mut result = String::with_capacity(s.len() + spaces.len());
        let mut space_index = 0;
        let s_bytes = s.as_bytes();

        for (i, &ch) in s_bytes.iter().enumerate() {
            if space_index < spaces.len() && i == spaces[space_index] as usize {
                result.push(' ');
                space_index += 1;
            }
            result.push(ch as char);
        }

        result
    }
}

2)
impl Solution {
    pub fn add_spaces(s: String, spaces: Vec<i32>) -> String {
        let mut result = String::with_capacity(s.len() + spaces.len());
        let bytes = s.as_bytes(); 
        let mut space_iter = spaces.into_iter();
        let mut next_space = space_iter.next();

        let mut i = 0;
        while i < bytes.len() {
            if let Some(pos) = next_space {
                if i == pos as usize {
                    result.push(' ');
                    next_space = space_iter.next();
                }
            }
            result.push(bytes[i] as char);
            i += 1;
        }

        result
    }
}

3)
impl Solution {
    pub fn add_spaces(s: String, spaces: Vec<i32>) -> String {
        let n = s.len();
        let spaces_len = spaces.len();
        let mut result = String::with_capacity(n + spaces_len);
        let mut space_index = 0;

        let s_bytes = s.as_bytes();

        for i in 0..n {
            if space_index < spaces_len && i == spaces[space_index] as usize {
                result.push(' ');
                space_index += 1;
            }
            result.push(s_bytes[i] as char);
        }

        result
    }
}

4)
impl Solution {
    pub fn add_spaces(s: String, spaces: Vec<i32>) -> String {
        let mut result = String::with_capacity(s.len() + spaces.len());
        let mut space_iter = spaces.into_iter();
        let mut next_space = space_iter.next();

        for (i, c) in s.chars().enumerate() {
            if let Some(pos) = next_space {
                if i == pos as usize {
                    result.push(' ');
                    next_space = space_iter.next();
                }
            }
            result.push(c);
        }

        result
    }
}

5)
impl Solution {
    pub fn add_spaces(s: String, spaces: Vec<i32>) -> String {
        let mut result = String::with_capacity(s.len() + spaces.len());
        let mut space_index = 0;

        for (i, c) in s.chars().enumerate() {
            if space_index < spaces.len() && i == spaces[space_index] as usize {
                result.push(' ');  
                space_index += 1;
            }
            result.push(c);  
        }

        result
    }
}
