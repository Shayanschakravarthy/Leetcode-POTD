use std::collections::BinaryHeap;

impl Solution {
    pub fn pick_gifts(gifts: Vec<i32>, k: i32) -> i64 {
        let mut max_heap: BinaryHeap<i32> = BinaryHeap::from(gifts);
        for _ in 0..k {
            if let Some(top) = max_heap.pop() {
                max_heap.push((top as f64).sqrt() as i32);
            }
        }
        max_heap.into_iter().map(|x| x as i64).sum()
    }
}
