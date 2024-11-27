class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; ++i)
            graph[i].push_back(i + 1);
        
        vector<int> dist(n, -1);
        auto bfs = [&]() {
            fill(dist.begin(), dist.end(), -1);
            dist[0] = 0;
            queue<int> q;
            q.push(0);
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : graph[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        };
        
        bfs(); 
        vector<int> result;
        
        for (auto& query : queries) {
            graph[query[0]].push_back(query[1]);
            if (dist[query[1]] == -1 || dist[query[1]] > dist[query[0]] + 1) {
                bfs(); 
            }
            result.push_back(dist[n - 1]);
        }
        
        return result;
    }
};
