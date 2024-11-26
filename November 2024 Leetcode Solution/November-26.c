int findChampion(int n, int** edges, int edgesSize, int* edgesColSize) {
    int* indegree = (int*)calloc(n, sizeof(int));
    if (!indegree) return -1;

    for (int i = 0; i < edgesSize; i++) {
        indegree[edges[i][1]]++;
    }

    int champion = -1;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            if (champion != -1) {
                free(indegree);
                return -1; 
            }
            champion = i;
        }
    }

    free(indegree);
    return champion;
}
