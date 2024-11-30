class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> deg;

    void buildGraph(const vector<vector<int>>& pairs) {
        for (const auto& edge : pairs) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            deg[u]++;
            deg[v]--;
        }
    }

    vector<int> findEulerianPath(int start) {
        vector<int> result;
        stack<int> stk;
        stk.push(start);

        while (!stk.empty()) {
            int node = stk.top();
            if (adj[node].empty()) {
                result.push_back(node);
                stk.pop();
            } else {
                int next = adj[node].back();
                adj[node].pop_back();
                stk.push(next);
            }
        }
        return result;
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        adj.reserve(n);
        deg.reserve(n);

        buildGraph(pairs);

        int startNode = -1;
        for (const auto& [node, degree] : deg) {
            if (degree == 1) {
                startNode = node;
                break;
            }
        }
        if (startNode == -1) startNode = pairs[0][0];

        vector<int> eulerPath = findEulerianPath(startNode);
        reverse(eulerPath.begin(), eulerPath.end());

        vector<vector<int>> result;
        result.reserve(n);
        for (size_t i = 1; i < eulerPath.size(); ++i) {
            result.push_back({eulerPath[i - 1], eulerPath[i]});
        }

        return result;
    }
};
