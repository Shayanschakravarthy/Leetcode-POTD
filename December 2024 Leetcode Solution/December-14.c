long long continuousSubarrays(int* nums, int numsSize) {
    int start = 0;
    long long totalSubarrays = 0;
    int* maxDeque = (int*)malloc(numsSize * sizeof(int));
    int* minDeque = (int*)malloc(numsSize * sizeof(int));
    int maxFront = 0, maxBack = 0;
    int minFront = 0, minBack = 0;

    for (int end = 0; end < numsSize; end++) {
        while (maxBack > maxFront && nums[maxDeque[maxBack - 1]] <= nums[end]) {
            maxBack--;
        }
        maxDeque[maxBack++] = end;
        while (minBack > minFront && nums[minDeque[minBack - 1]] >= nums[end]) {
            minBack--;
        }
        minDeque[minBack++] = end;
        while (nums[maxDeque[maxFront]] - nums[minDeque[minFront]] > 2) {
            if (maxDeque[maxFront] == start) {
                maxFront++;
            }
            if (minDeque[minFront] == start) {
                minFront++;
            }
            start++;
        }
        totalSubarrays += (end - start + 1);
    }

    free(maxDeque);
    free(minDeque);
    return totalSubarrays;
}
