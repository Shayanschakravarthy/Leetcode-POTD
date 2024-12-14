typedef struct {
    int value;
    int index;
} Pair;

int compare(const void* a, const void* b) {
    Pair* p1 = (Pair*)a;
    Pair* p2 = (Pair*)b;
    if (p1->value == p2->value)
        return p1->index - p2->index;
    return p1->value - p2->value;
}

long long findScore(int* nums, int numsSize) {
    Pair* indexedNums = (Pair*)malloc(numsSize * sizeof(Pair));
    for (int i = 0; i < numsSize; i++) {
        indexedNums[i].value = nums[i];
        indexedNums[i].index = i;
    }

    qsort(indexedNums, numsSize, sizeof(Pair), compare);

    bool* vis = (bool*)calloc(numsSize, sizeof(bool));
    long long ans = 0;

    for (int i = 0; i < numsSize; i++) {
        int idx = indexedNums[i].index;
        if (!vis[idx]) {
            ans += indexedNums[i].value;
            vis[idx] = true;
            if (idx > 0) vis[idx - 1] = true;
            if (idx < numsSize - 1) vis[idx + 1] = true;
        }
    }

    free(indexedNums);
    free(vis);
    return ans;
}
