impl Solution {
    pub fn max_two_events(events: Vec<Vec<i32>>) -> i32 {
        let mut events = events;
        events.sort();

        let n = events.len();
        let mut max_values = vec![0; n];
        max_values[n - 1] = events[n - 1][2];

        for i in (0..n - 1).rev() {
            max_values[i] = max_values[i + 1].max(events[i][2]);
        }

        let mut max_result = 0;
        for i in 0..n {
            let value = events[i][2];
            let idx = events.binary_search_by(|event| event[0].cmp(&(events[i][1] + 1))).unwrap_or_else(|x| x);
            let total_value = if idx < n { value + max_values[idx] } else { value };
            max_result = max_result.max(total_value);
        }

        max_result
    }
}
