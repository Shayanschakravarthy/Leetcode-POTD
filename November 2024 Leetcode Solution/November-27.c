int* shortestDistanceAfterQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int* result = (int*)malloc(queriesSize * sizeof(int));
    int** graph = (int**)malloc(n * sizeof(int*));
    int* sizes = (int*)calloc(n, sizeof(int));
    
    for (int i = 0; i < n; ++i) {
        graph[i] = (int*)malloc(n * sizeof(int));
        if (i < n - 1) graph[i][sizes[i]++] = i + 1;
    }
    
    int* dist = (int*)malloc(n * sizeof(int));
    
    void bfs() {
        memset(dist, -1, n * sizeof(int));
        dist[0] = 0;
        int* queue = (int*)malloc(n * sizeof(int));
        int front = 0, back = 0;
        queue[back++] = 0;
        
        while (front < back) {
            int u = queue[front++];
            for (int i = 0; i < sizes[u]; ++i) {
                int v = graph[u][i];
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    queue[back++] = v;
                }
            }
        }
        free(queue);
    }
    
    bfs();
    
    for (int i = 0; i < queriesSize; ++i) {
        int u = queries[i][0], v = queries[i][1];
        graph[u][sizes[u]++] = v;
        if (dist[v] == -1 || dist[v] > dist[u] + 1) {
            bfs();
        }
        result[i] = dist[n - 1];
    }
    
    for (int i = 0; i < n; ++i) free(graph[i]);
    free(graph);
    free(sizes);
    free(dist);
    return result;
}
