/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* isArraySpecial(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    bool* result = (bool*)malloc(queriesSize * sizeof(bool));
    int* d = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        d[i] = i;
    }
    for (int i = 1; i < numsSize; ++i) {
        if ((nums[i] % 2) != (nums[i - 1] % 2)) {
            d[i] = d[i - 1];
        }
    }
    for (int i = 0; i < queriesSize; ++i) {
        int f = queries[i][0];
        int t = queries[i][1];
        result[i] = (d[t] <= f);
    }
    free(d);

    return result;
}
