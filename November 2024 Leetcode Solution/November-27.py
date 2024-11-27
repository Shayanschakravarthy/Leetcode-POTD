from collections import deque
from typing import List
class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        g = {i: [i + 1] for i in range(n - 1)}
        ans = []
        def bfs() -> int:
            q = deque([0])
            dist = [-1] * n
            dist[0] = 0  
            while q:
                u = q.popleft()
                for v in g[u]:
                    if dist[v] == -1:  
                        dist[v] = dist[u] + 1
                        if v == n - 1:  
                            return dist[v]
                        q.append(v)
            return -1  
        for u, v in queries:
            g[u].append(v)  
            ans.append(bfs())  
        return ans
