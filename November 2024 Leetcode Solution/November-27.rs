use std::collections::{HashSet, VecDeque};
impl Solution {
    pub fn shortest_distance_after_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let n = n as usize;
        let mut graph: Vec<HashSet<usize>> = vec![HashSet::new(); n];
        for i in 0..n - 1 {
            graph[i].insert(i + 1);
        }
        let bfs = |graph: &Vec<HashSet<usize>>, n: usize| -> i32 {
            let mut dist = vec![-1; n];  
            let mut queue = VecDeque::new();
            dist[0] = 0; 
            queue.push_back(0);
            while let Some(u) = queue.pop_front() {
                for &v in &graph[u] {
                    if dist[v] == -1 {  
                        dist[v] = dist[u] + 1;
                        if v == n - 1 {  
                            return dist[v];
                        }
                        queue.push_back(v);
                    }
                }
            }
            -1  
        };
        let mut result = Vec::with_capacity(queries.len());
        for query in queries {
            let (u, v) = (query[0] as usize, query[1] as usize);
            if !graph[u].contains(&v) {
                graph[u].insert(v);
            }
            result.push(bfs(&graph, n));
        }
        result
    }
}
