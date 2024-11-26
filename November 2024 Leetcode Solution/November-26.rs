impl Solution {
    pub fn find_champion(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let mut indegree = std::collections::HashMap::new();

        for edge in edges {
            *indegree.entry(edge[1]).or_insert(0) += 1;
        }

        let mut champion = -1;

        for i in 0..n {
            if indegree.get(&i).copied().unwrap_or(0) == 0 {
                if champion != -1 {
                    return -1; 
                }
                champion = i;
            }
        }

        champion
    }
}
