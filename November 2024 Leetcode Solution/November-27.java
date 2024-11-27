import java.util.*;
class Solution {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        List<Set<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new HashSet<>());
        }
        for (int i = 0; i < n - 1; i++) {
            graph.get(i).add(i + 1); 
        }
        int[] result = new int[queries.length];
        int[] dist = new int[n]; 
        for (int i = 0; i < queries.length; i++) {
            int u = queries[i][0], v = queries[i][1];
            if (!graph.get(u).contains(v)) {
                graph.get(u).add(v); 
            }
            Arrays.fill(dist, -1); 
            result[i] = bfs(graph, dist, n);
        }
        return result;
    }
    private int bfs(List<Set<Integer>> graph, int[] dist, int n) {
        dist[0] = 0;
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(0);
        while (!queue.isEmpty()) {
            int u = queue.poll();
            for (int v : graph.get(u)) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    if (v == n - 1) {
                        return dist[v];
                    }
                    queue.offer(v);
                }
            }
        }
        return -1; 
    }
}
