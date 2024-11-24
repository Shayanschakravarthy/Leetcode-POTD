
impl Solution {
    pub fn max_matrix_sum(matrix: Vec<Vec<i32>>) -> i64 {
        let mut total_sum: i64 = 0;
        let mut min_abs_value = i32::MAX;
        let mut negative_count = 0;

        for row in matrix.iter() {
            for &value in row.iter() {
                let abs_value = value.abs();
                total_sum += abs_value as i64;
                if abs_value < min_abs_value {
                    min_abs_value = abs_value;
                }
                if value < 0 {
                    negative_count += 1;
                }
            }
        }

        if negative_count % 2 != 0 {
            total_sum -= 2 * min_abs_value as i64;
        }

        total_sum
    }
}
